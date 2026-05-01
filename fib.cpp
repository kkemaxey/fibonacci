#include <iostream>
#include <fstream>
#include <chrono>
using namespace std;
using namespace std::chrono;

long long fibIterative (int);
long long fibRecursive (int);
void timeAndPrint (int, bool, ofstream&);
void runBenchmark ();


//--------------------------------------------------------------------------------------------------------------
// Main function that runs the benchmark
//--------------------------------------------------------------------------------------------------------------

int main ()
{
    runBenchmark();
    return 0;
}


//--------------------------------------------------------------------------------------------------------------
// Iterative approach: uses two running variables to build up to F(n) without any call stack overhead.
// Starts from the base cases F(1)=1 and F(2)=2, then shifts the window forward one step per iteration.
// Time complexity  : O(n)
// Space complexity : O(1)
//--------------------------------------------------------------------------------------------------------------

long long fibIterative (int n)
{
    if (n == 1) return 1;
    if (n == 2) return 2;

    long long prev2 = 1;   // F(n-2)
    long long prev1 = 2;   // F(n-1)
    long long current = 0;

    for (int i = 3; i <= n; i++)
    {
        current = prev1 + prev2;
        prev2   = prev1;
        prev1   = current;
    }

    return current;
}


//--------------------------------------------------------------------------------------------------------------
// Recursive approach: directly mirrors the mathematical definition F(n) = F(n-1) + F(n-2).
// Each call branches into two sub-calls until it hits the base cases F(1)=1 or F(2)=2.
// Time complexity  : O(2^n)  — exponential due to redundant recomputation of sub-problems
// Space complexity : O(n)    — maximum call stack depth at any point
//--------------------------------------------------------------------------------------------------------------

long long fibRecursive (int n)
{
    if (n == 1) return 1;
    if (n == 2) return 2;

    return fibRecursive(n - 1) + fibRecursive(n - 2);
}


//--------------------------------------------------------------------------------------------------------------
// Times a single call to either the iterative or recursive function for a given n.
// Uses high_resolution_clock to measure duration in microseconds, then prints the value and elapsed time.
// The boolean flag useRecursive selects which implementation to benchmark.
// The ofstream& csv parameter is used to write the results to a CSV file.
//--------------------------------------------------------------------------------------------------------------

void timeAndPrint (int n, bool useRecursive, ofstream& csv)
{
    long long result;

    auto start = high_resolution_clock::now();

    if (useRecursive)
    {
        result = fibRecursive(n);
    }
    else
    {
        result = fibIterative(n);
    }

    auto stop     = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "  F(" << n << ") = " << result
         << "  |  Time: " << duration.count() << " microseconds" << endl;

    csv << (useRecursive ? "recursive" : "iterative")
        << ',' << n << ',' << duration.count() << ',' << result << '\n';
}


//--------------------------------------------------------------------------------------------------------------
// Drives the full benchmark across the required set of n values {10,20,30,35,40,45,50,55}.
// Prints a clearly labeled section for each method so results can be directly copied into the assignment table.
//--------------------------------------------------------------------------------------------------------------

void runBenchmark ()
{
    int testValues[] = {10, 20, 30, 35, 40, 45, 50, 55};
    int numTests = sizeof(testValues) / sizeof(testValues[0]);

    ofstream csv("results.csv");
    csv << "method,n,time_microseconds,result\n";

    cout << "=======================================" << endl;
    cout << "          Fibonacci Benchmark          " << endl;
    cout << "   F(1)=1, F(2)=2, F(n)=F(n-1)+F(n-2)" << endl;
    cout << "=======================================" << endl;

    cout << endl << "--- Iterative Method ---" << endl;
    for (int i = 0; i < numTests; i++)
    {
        timeAndPrint(testValues[i], false, csv);
    }

    cout << endl << "--- Recursive Method ---" << endl;
    for (int i = 0; i < numTests; i++)
    {
        timeAndPrint(testValues[i], true, csv);
    }

    cout << endl << "=======================================" << endl;
}
