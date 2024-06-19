#include <iostream>

// Function for modular exponentiation
int modExp(int base, int exp, int MOD)
{
    int result = 1;
    while (exp > 0)
    {
        if (exp % 2 == 1)
        {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        exp /= 2;
    }
    return result;
}

// Function for modular addition
int modAdd(int a, int b, int MOD)
{
    return (a % MOD + b % MOD) % MOD;
}

// Function for modular subtraction
int modSub(int a, int b, int MOD)
{
    return ((a % MOD - b % MOD) + MOD) % MOD;
}

// Function for modular multiplication
int modMul(int a, int b, int MOD)
{
    return (a % MOD * b % MOD) % MOD;
}

// Function for modular division
int modDiv(int a, int b, int MOD)
{
    return (a % MOD * modExp(b, MOD - 2, MOD)) % MOD;
}

int main()
{
    const int MOD = 1000000007; // Example value for MOD

    int a = 10, b = 20;

    int addition = modAdd(a, b, MOD);
    int subtraction = modSub(a, b, MOD);
    int multiplication = modMul(a, b, MOD);
    int division = modDiv(a, b, MOD); // Assuming b is not zero and has an inverse

    // Output results
    std::cout << "Addition: " << addition << std::endl;
    std::cout << "Subtraction: " << subtraction << std::endl;
    std::cout << "Multiplication: " << multiplication << std::endl;
    std::cout << "Division: " << division << std::endl;

    return 0;
}
