#include <iostream>
#include <cstddef>
#include <algorithm>


#ifndef MYLIB_NUM_NODES_PER_CHUNK
#define MYLIB_NUM_NODES_PER_CHUNK 128

#endif

namespace mylib {
	class object_pool
	{
		static const unsigned char num_nodes_per_chunk = MYLIB_NUM_NODES_PER_CHUNK;

		typedef unsigned char counter_type;

		struct chunk_data
		{
			counter_type free_node_count;
			chunk_data *next;
		};

		static const size_t chunk_data_size = sizeof(chunk_data);

		chunk_data *chunk_data_head;

		struct free_node
		{
			counter_type bias;
			free_node *next;
		};

		static const size_t free_node_offset = offsetof(free_node, next);
		free_node *free_node_head;

		const size_t node_size;
		const size_t free_node_size;
		const size_t chunk_size;

	public:
		object_pool(size_t node_size) :
			chunk_data_head(0), free_node_head(0),
			node_size(node_size),
			free_node_size(free_node_offset +
						   std::max(sizeof(free_node*), node_size)),
			chunk_size(chunk_data_size +
				free_node_size * num_nodes_per_chunk)
			{}

		~object_pool() {
			while(chunk_data_head) {
				chunk_data *chunk = chunk_data_head;
				chunk_data_head = chunk_data_head->next;
				operator delete (chunk);
			}
		}

		void* allocate();

		void deallocate(void *ptr);

		size_t recycle();
	};

	class object_pool_array {
		size_t sz;
		object_pool *array;
	public:
		object_pool_array(size_t sz, size_t step) :
			sz(sz),
			array(static_cast<object_pool*>(operator new (sizeof(object_pool) * sz)))
			{
				for(size_t i = 0; i < sz; ++i)
				    new (array + i) object_pool(i * step + step);
			}

		~object_pool_array() {
			for(size_t i = 0; i < sz; ++i)
				(array + i)->~object_pool();
			operator delete (array);
		}

		size_t size() const {
			return sz;
		}

		object_pool& operator[] (size_t n) {
			return array[n];
		}
	};
};

