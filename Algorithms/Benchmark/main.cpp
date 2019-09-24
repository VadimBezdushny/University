#include <iostream>
#include <chrono>
#include <vector>
#include <array>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <random>
#include <functional>

struct InputData {
    size_t n;
    size_t max_weight;
    std::vector<int> weights;
    std::vector<int> values;

    void Read(std::istream &is) {
        is >> max_weight >> n;
        weights.resize(n);
        values.resize(n);
        for (size_t i = 0; i < n; i++) {
            is >> weights[i] >> values[i];
        }
    }

    void Print(std::ostream &os) {
        os << n << " " << max_weight << std::endl;
        for (int i = 0; i < n; i++) {
            os << weights[i] << " " << values[i] << std::endl;
        }
    }
};

class BruteForceSolver {
    static constexpr int kMinInfinity = std::numeric_limits<int>::min();

public:
    int Solve(const InputData &data) {
        if (data.n >= 30) return 0;

        int max_total_value = 0;
        for (int mask = 0; mask < (1 << data.n); ++mask) {
            int total_weight = 0, total_value = 0;
            for (int j = 0; j < data.n; j++) {
                if((mask >> j) & 1){
                    total_weight += data.weights[j];
                    total_value += data.values[j];
                }
            }
            if(total_weight <= data.max_weight){
                max_total_value = std::max(max_total_value, total_value);
            }
        }
        return max_total_value;
    }
};

class DpSolver {
    static constexpr int kMinInfinity = std::numeric_limits<int>::min();

public:
    int Solve(const InputData &data) {
        std::vector<int> dp(data.max_weight + 1, kMinInfinity);
        dp[0] = 0;

        for (size_t i = 0; i < data.n; i++) {
            int value = data.values[i];
            int weight = data.weights[i];

            for (int j = data.max_weight; j >= weight; j--) {
                dp[j] = std::max(dp[j], dp[j - weight] + value);
            }
        }

        return *std::max_element(dp.begin(), dp.end());
    }
};

class TestGenerator {
public:
    struct GeneratorOptions {
        size_t array_size;
        size_t max_weight;
        double max_weight_sampling; // from 0 to 1
        size_t max_value;
    };

    InputData generateInput(GeneratorOptions options) {
        InputData inputData;

        std::mt19937 mt(1834);

        int max_weight_per_element = static_cast<int>(options.max_weight * options.max_weight_sampling);
        std::uniform_int_distribution<int> weight_distribution(0, max_weight_per_element);
        std::uniform_int_distribution<int> value_distribution(0, options.max_value);

        inputData.n = options.array_size;
        inputData.max_weight = options.max_weight;

        inputData.weights.resize(inputData.n);
        inputData.values.resize(inputData.n);

        for (int i = 0; i < inputData.n; i++) {
            inputData.weights[i] = weight_distribution(mt);
            inputData.values[i] = value_distribution(mt);
        }

        return inputData;
    }

};

using duration = std::chrono::steady_clock::duration;


std::pair<int, int> MeasureAlgorithm(std::function<int()> f){
    auto start = std::chrono::high_resolution_clock::now();
    auto answer = f();
    auto end = std::chrono::high_resolution_clock::now();
    return {std::chrono::duration_cast<std::chrono::microseconds>(end - start).count(), answer};
}


class TestSuite {
public:
    const std::vector<TestGenerator::GeneratorOptions> suite_options = {
            {1, 100, 0.2, 1000},
            {1, 10000, 0.2, 1000}
    };

    void Generate() {
        int test_number = 0;
        for (auto test_option : suite_options) {
            std::ofstream out("results_test_" + std::to_string(++test_number) + ".csv");
            out << "dp, brute" << std::endl;
            std::cerr << std::endl;
            for(test_option.array_size  = 1; test_option.array_size  <= 24; test_option.array_size ++){
                InputData data = TestGenerator().generateInput(test_option);

                std::cerr << data.n << ", ";
                auto dp_results = MeasureAlgorithm([data]{
                    return DpSolver().Solve(data);
                });

                auto brute_results = MeasureAlgorithm([data]{
                    return BruteForceSolver().Solve(data);
                });

                out << dp_results.first <<  ", " << brute_results.first << std::endl;
                if(dp_results.second != brute_results.second){
                    std::cout << "FAIL:" << dp_results.second << " " << brute_results.second << std::endl;
                }
            }

        }
    }
};

int main() {
#ifdef LOCAL
    std::ifstream cin("input.txt");
#else
    using std::cin;
#endif


//    InputData inputData;
//    inputData.Read(cin);
//
//    std::cout << DpSolver().Solve(inputData);

    TestSuite().Generate();
    return 0;
}