#include <iostream>
#include <string>

long long factorial_recursive(int n) {
    if (n <= 1) return 1;
    return n * factorial_recursive(n - 1);
}

long long factorial_iterative(int n) {
    long long result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <mode: 1 (recursive) or 2 (iterative)>\n";
        return 1;
    }

    int mode = std::stoi(argv[1]);
    unsigned long long sum = 0;
   
    for (long long i = 0; i < 50000000; ++i) {
        if (mode == 1) {
            sum += factorial_recursive(20);
        } else {
            sum += factorial_iterative(20);
        }
    }
    
    return 0;
}
