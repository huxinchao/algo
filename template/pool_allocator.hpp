#pragma once
#include <new>
#include <memory>
#include "object_pool.hpp"

#ifndef MYLIB_POOL_ALLOCATOR_SIZE_STEP
#define MYLIB_POOL_ALLOCATOR_SIZE_STEP 8
#endif


#ifndef MYLIB_POOL_ALLOCATOR_POOL_SIZE
#define MYLIB_POOL_ALLOCATOR_POOL_SIZE 64
#endif

namespace mylib {
	class pool_allocator_base
	{
	public:
		static const size_t align = MYLIB_POOL_ALLOCATOR_SIZE_STEP;
		static const size_t pool_size = MYLIB_POOL_ALLOCATOR_POOL_SIZE;
		static const size_t max_size = align * pool_size;
		static object_pool_array pool;

		void* base_allocate(size_t n) {
			if(n == 0) 
				return NULL;
			else if(n > max_size) 
				return static_cast<void*>(operator new (n));
			else
				return pool[(n + align - 1) / align - 1].allocate();
		}

		void base_deallocate(void *ptr, size_t n) {
			if(n > max_size)
				operator delete (ptr);
			else
				pool[(n + align - 1) / align - 1].deallocate(ptr); 
		}

		static size_t recycle() {
			size_t recycled_bytes = 0;
			for(size_t i = 1; i < pool.size(); ++i)
				recycled_bytes += pool[i].recycle();
			return recycled_bytes;
		}
	};

	inline
	size_t pool_allocator_recycle() {
		return pool_allocator_base::recycle();
	}

	template<typename T>
	class pool_allocator : private pool_allocator_base
	{
	public:
		typedef size_t size_type;
		typedef ptrdiff_t difference_type;
		typedef T* pointer;
		typedef const T* const_pointer;
		typedef T& reference;
		typedef const T& const_reference;
		typedef T value_type;

		template<typename T1>
		struct rebind {
			typedef pool_allocator<T1> other;
		};

		pool_allocator() {}
		pool_allocator(pool_allocator const&) {}
		template<typename T1>
		pool_allocator(const pool_allocator<T1>&) {}
		~pool_allocator() {}


		pointer address(reference r) const {
			return &r;
		}
		const_pointer address(const_reference r) const {
			return &r;
		}

		void construct(pointer ptr, const_reference v) {
			new ((void*)ptr) T(v);
		}

		void destroy(pointer ptr) {
			ptr->~T();
		}

		pointer allocate(size_type n, const void* = 0) {
			return static_cast<pointer>(base_allocate(n * sizeof(T)));
		}

		void deallocate(pointer ptr, size_type n) {
			return base_deallocate(ptr, n * sizeof(T));
		}
	};

	template<typename T>
	inline bool operator == (const pool_allocator<T>&, const pool_allocator<T>&) {
		return true;
	}

	template<typename T>
	inline bool operator != (const pool_allocator<T>&, const pool_allocator<T>&) {
		return false;
	}

	object_pool_array
	pool_allocator_base::pool(pool_allocator_base::pool_size, pool_allocator_base::align);
};
