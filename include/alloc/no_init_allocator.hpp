#ifndef ALLOC_NO_INIT_ALLOCATOR_HPP
#define ALLOC_NO_INIT_ALLOCATOR_HPP

#include <cstdint>
#include <iostream>
#include <type_traits>

namespace alloc {

template<typename T>
class no_init_allocator {
public:
	typedef T value_type;

	no_init_allocator() = default;

	template <class Other>
	no_init_allocator(const no_init_allocator<Other>&) {}
	T* allocate(std::size_t n) {
		return reinterpret_cast<T*>(::operator new(n * sizeof(T)));
	}
	void deallocate(T* p, std::size_t n) {
		::operator delete(p, n);
	}

	void construct(T*){
		// do nothing
	}
	void destroy(T*) {
		// do nothing
	}

	static_assert(std::is_pod<T>::value,
			"no_init_allocator must only be used with POD-types");
};

template <class T, class U>
bool operator==(const no_init_allocator<T>&, const no_init_allocator<U>&) {
	return true;
}

template <class T, class U>
bool operator!=(const no_init_allocator<T>&, const no_init_allocator<U>&) {
	return false;
}


} //namespace



#endif
