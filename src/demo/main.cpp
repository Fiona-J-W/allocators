#include <vector>
#include "alloc/no_init_allocator.hpp"

int main() {
	auto buffer = std::vector<int, alloc::no_init_allocator<int>>(1024);
	buffer[10] = 23;
}
