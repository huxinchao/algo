#include "object_pool.hpp"
#include <new>

namespace mylib {
	template<typename T0, typename T1>
	inline
	T0* byte_shift(T1* ptr, size_t b)
	{
		return reinterpret_cast<T0*>(reinterpret_cast<char*>(ptr) + b);
	}

	void* object_pool::allocate() {
		if(!free_node_head) {
			chunk_data *new_chunk = reinterpret_cast<chunk_data*>(operator new(chunk_size));
			new_chunk->next = chunk_data_head;
			chunk_data_head = new_chunk;

			free_node_head = byte_shift<free_node>(new_chunk, chunk_data_size);
			free_node_head->bias = 0;
			free_node_head->next = 0;

			for(size_t node_index = 1; node_index < num_nodes_per_chunk; ++node_index) {
				free_node *f = byte_shift<free_node>(free_node_head, free_node_size);
				f->bias = free_node_head->bias + 1;
				f->next = free_node_head;
				free_node_head = f;
			}
		}

   		free_node *return_node = free_node_head;
   		free_node_head = free_node_head->next;
  		return static_cast<void*>(&(return_node->next));

	}

	void object_pool::deallocate(void *ptr) {
		free_node *f = byte_shift<free_node>(ptr, -1 * free_node_offset);
		f->next = free_node_head;
		free_node_head = f;
	}

	size_t object_pool::recycle() {
		size_t *shift_table = new size_t [num_nodes_per_chunk];
		shift_table[0] = -1 * chunk_data_size;
		for(size_t i = 1; i < num_nodes_per_chunk; ++i)
			shift_table[i] = shift_table[i-1] -free_node_size;

		for(chunk_data *p = chunk_data_head; p; p = p->next)
			p->free_node_count = 0;

		for(free_node *f = free_node_head; f; f = f->next) {
			chunk_data *chunk = byte_shift<chunk_data>(f, shift_table[f->bias]);
			++chunk->free_node_count;
		}

		for(free_node **pp = &free_node_head; *pp;) {
			chunk_data *chunk =
				byte_shift<chunk_data>(*pp, shift_table[(*pp)->bias]);
			if(chunk->free_node_count == num_nodes_per_chunk)
				*pp = (*pp)->next;
			else
				pp = &((*pp)->next);
		}

		size_t num_recycled = 0;
		for(chunk_data **pp = &chunk_data_head; *pp;) {
			if((*pp)->free_node_count == num_nodes_per_chunk) {
				chunk_data *p = *pp;
				*pp = (*pp)->next;
				operator delete (p);
				++num_recycled;
			}
			else {
				pp = &((*pp)->next);
			}
		}

		delete [] shift_table;
		return num_recycled * chunk_size;
	}
}
