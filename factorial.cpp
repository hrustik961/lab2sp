#include <iostream>
#include <vector>
#include <cstdint>

__attribute__((noinline)) void compute_array(uint32_t *__restrict__ a, const uint32_t *__restrict__ b, size_t n)
{
#pragma GCC ivdep
    for (size_t i = 0; i < n; ++i)
    {
        a[i] = a[i] * b[i] + 3u;
    }
}

int main()
{
    const size_t N = 16384;
    std::vector<uint32_t> a(N, 2u);
    std::vector<uint32_t> b(N, 5u);

    const size_t ITERATIONS = 400000;

    for (size_t iter = 0; iter < ITERATIONS; ++iter)
    {
        compute_array(a.data(), b.data(), N);
        asm volatile("" : : "r"(a.data()) : "memory");
    }

    volatile uint32_t check = a[N / 2];
    std::cout << "Check element: " << check << std::endl;

    return 0;
}