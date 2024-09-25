#include <vector>
#include <cstdint>
#include <iostream>
#include <string.h>
#include <ctime>
#include <fstream>
#include <cstring>
#include <iomanip>

int MaxSubSum1(std::vector<int> a) {
    int maxSum = 0;
    for (int i = 0; i < a.size(); ++i) {
        for (int j = 1; j < a.size(); ++j) {
            int thisSum = 0;

            for (int k = i; k <= j; ++k) {
                thisSum += a[k];
            }

            if (thisSum > maxSum) {
                maxSum = thisSum;
            }
        }
    }
    return maxSum;
}

int MaxSubSum2(std::vector<int> a) {
    int maxSum = 0;

    for (int i = 0; i < a.size(); ++i) {
        int thisSum = 0;

        for (int j = i; j < a.size(); ++j) {
            thisSum += a[j];

            if (thisSum > maxSum) {
                maxSum = thisSum;
            }
        }
    }
    return maxSum;
}

int MaxSubSum3(std::vector<int> a){
    int sum = 0;
    int max_sum = 0;
    int min_sum = 0;
    int min_index = 0;
    int max_start = 0;
    int max_end = 0;

    for(unsigned int i = 0; i < a.size(); i++){
        sum += a[i];

        if(sum < min_sum){
            min_sum = sum;
            min_index = i;
        }

        if(sum - min_sum > max_sum){
            max_sum = sum - min_sum;
            max_start = min_index + 1;
            max_end = i + 1;
        }
    }
    return max_sum;
}

int MaxSubSum4(std::vector<int> a) {
    int max_so_far = 0;
    int max_ending_here = 0;

    for (unsigned int i = 0; i < a.size(); i++) {
        max_ending_here += a[i];

        if (max_so_far < max_ending_here) {
            max_so_far = max_ending_here;
        }

        if (max_ending_here < 0) {
            max_ending_here = 0;
        }
    }
    return max_so_far;
}

float time_func(std::vector<int> n, const char *name) {
    uint64_t val;
    unsigned long c_start, c_end;
    if (! strcmp(name, "MaxSubSum1")) {
        c_start = std::clock();
        val = MaxSubSum1(n);
        c_end = std::clock();
    }
    else if (! strcmp(name, "MaxSubSum2")) {
        c_start = std::clock();
        val = MaxSubSum2(n);
        c_end = std::clock();
    }
    else if (! strcmp(name, "MaxSubSum3")) {
        c_start = std::clock();
        val = MaxSubSum3(n);
        c_end = std::clock();
    }
    else if (! strcmp(name, "MaxSubSum4")) {
        c_start = std::clock();
        val = MaxSubSum4(n);
        c_end = std::clock();
    }
    else{
        std::cout << "Invalid function call" << std::endl;
    }

    float output = 1.0 * (c_end - c_start) / CLOCKS_PER_SEC;;
    return output;
}

int main(int argc, char**argv) {
    if (argc != 3) {
        std::cout << "Usage: ./MaxSub <n <alg\n";
        std::cout << "\t<n\tn-th term to be calculated\n";
        std::cout << "\t<alg\talgorithm to be used (euler1 or euler2)\n";
        return 0;
    }

    if(std::strlen(argv[1]) > 9) {
        std::cout << "Error: input value for n is too large" << std::endl;
        return 1;
    }

    uint64_t Max_Number = (uint64_t) atoi(argv[1]);

    std::ofstream myfile;

    myfile.open(std::to_string(Max_Number)+ "_" + (char *)argv[2]+".csv");

    myfile << "input" << "," << "time" << '\n';

    for (int i = 0; i <= Max_Number; i++){
        float function_time = time_func(std::vector<int>(i), argv[2]);
        myfile << i << "," << std::fixed << std::setprecision(4) << function_time<<'\n';

    }
    myfile.close();
    return 0;
}