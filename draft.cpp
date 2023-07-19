#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>
// #include "sort.h" // Include the header file with your sorting algorithms

using namespace std;

void printUsage() {
    cout << "Usage: [Execution file] -a [Algorithm] [Given input] [Output parameter(s)]\n"
         << "       [Execution file] -a [Algorithm] [Input size] [Input order] [Output parameter(s)]\n"
         << "       [Execution file] -a [Algorithm] [Input size] [Output parameter(s)]\n"
         << "       [Execution file] -c [Algorithm 1] [Algorithm 2] [Given input]\n"
         << "       [Execution file] -c [Algorithm 1] [Algorithm 2] [Input size] [Input order]\n";
}

vector<int> readInputDataFromFile(const string& filename) {
    vector<int> data;
    ifstream inputFile(filename);
    if (inputFile.is_open()) {
        int n;
        inputFile >> n;
        data.reserve(n);
        int num;
        while (inputFile >> num) {
            data.push_back(num);
        }
        inputFile.close();
    } else {
        cerr << "Error: Unable to open file " << filename << endl;
    }
    return data;
}

vector<int> generateInputData(int size, const string& order) {
    vector<int> data;
    if (order == "-rand") {
        for (int i = 0; i < size; ++i) {
            data.push_back(rand() % size);
        }
    } else if (order == "-nsorted") {
        for (int i = 0; i < size; ++i) {
            data.push_back(i + (rand() % 10));
        }
    } else if (order == "-sorted") {
        for (int i = 0; i < size; ++i) {
            data.push_back(i);
        }
    } else if (order == "-rev") {
        for (int i = size - 1; i >= 0; --i) {
            data.push_back(i);
        }
    } else {
        cerr << "Error: Invalid input order specified!" << endl;
    }
    return data;
}

void runSortingAlgorithm(const string& algorithm, const vector<int>& data, const vector<string>& outputParams) {
    if (algorithm == "selection-sort") {
        // Call your selection sort function here and measure running time and/or comparisons
        // Example: auto start_time = chrono::high_resolution_clock::now();
        //          selectionSort(data);
        //          auto end_time = chrono::high_resolution_clock::now();
        //          auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();
        //          int comparisons = getSelectionSortComparisons();
        // Use "duration" and "comparisons" to handle -time, -comp, or -both options in outputParams
    } else if (algorithm == "insertion-sort") {
        // Implement and measure insertion sort in a similar manner as above
    } else if (algorithm == "merge-sort") {
        // Implement and measure merge sort in a similar manner as above
    } else if (algorithm == "quick-sort") {
        // Implement and measure quick sort in a similar manner as above
    } else if (algorithm == "heap-sort") {
        // Implement and measure heap sort in a similar manner as above
    } else if (algorithm == "radix-sort") {
        // Implement and measure radix sort in a similar manner as above
    } else if (algorithm == "binary-insertion-sort") {
        // Implement and measure binary insertion sort in a similar manner as above
    } else {
        cerr << "Error: Unknown algorithm specified!" << endl;
    }
}

void runComparisonMode(const string& algorithm1, const string& algorithm2, const vector<int>& data) {
    // Call your sorting algorithms for both algorithm1 and algorithm2, and measure their running times and/or comparisons
    // Example: auto start_time_algo1 = chrono::high_resolution_clock::now();
    //          algorithm1(data);
    //          auto end_time_algo1 = chrono::high_resolution_clock::now();
    //          auto duration_algo1 = chrono::duration_cast<chrono::microseconds>(end_time_algo1 - start_time_algo1).count();
    //          int comparisons_algo1 = getAlgorithm1Comparisons();
    // Use "duration_algo1" and "comparisons_algo1" to handle the first sorting algorithm's output

    // Implement the same process for the second sorting algorithm (algorithm2)

    // Print out the results for both algorithms
    // Example: cout << algorithm1 << " Running Time: " << duration_algo1 << " microseconds" << endl;
    //          cout << algorithm1 << " Comparisons: " << comparisons_algo1 << endl;
}

int main(int argc, char* argv[]) {
    if (argc < 4) {
        printUsage();
        return 1;
    }

    string mode = argv[1];
    if (mode != "-a" && mode != "-c") {
        cerr << "Error: Invalid mode specified!" << endl;
        printUsage();
        return 1;
    }

    if (mode == "-a") {
        string algorithm = argv[2];

        // Handle Algorithm mode
        if (argc == 5) {
            string inputOrder = argv[3];
            vector<string> outputParams = {argv[4]};
            int inputSize = stoi(inputOrder);
            runSortingAlgorithm(algorithm, generateInputData(inputSize, "-rand"), outputParams);
        } else if (argc == 6) {
            if (string(argv[4]).substr(0, 1) == "-") {
                string inputOrder = argv[4];
                vector<string> outputParams = {argv[5]};
                int inputSize = stoi(argv[3]);
                runSortingAlgorithm(algorithm, generateInputData(inputSize, inputOrder), outputParams);
            } else {
                string inputFile = argv[3];
                vector<string> outputParams = {argv[4]};
                vector<int> data = readInputDataFromFile(inputFile);
                runSortingAlgorithm(algorithm, data, outputParams);
            }
        } else if (argc == 7) {
            string inputFile = argv[3];
            vector<string> outputParams = {argv[4], argv[5]};
            vector<int> data = readInputDataFromFile(inputFile);
            runSortingAlgorithm(algorithm, data, outputParams);
        } else {
            cerr << "Error: Invalid number of arguments for Algorithm mode!" << endl;
            printUsage();
            return 1;
        }

    } else if (mode == "-c") {
        if (argc == 6) {
            string algorithm1 = argv[2];
            string algorithm2 = argv[3];
            string inputFile = argv[4];
            vector<int> data = readInputDataFromFile(inputFile);
            runComparisonMode(algorithm1, algorithm2, data);
        } else if (argc == 7) {
            string algorithm1 = argv[2];
            string algorithm2 = argv[3];
            int inputSize = stoi(argv[4]);
            string inputOrder = argv[5];
            vector<int> data = generateInputData(inputSize, inputOrder);
            runComparisonMode(algorithm1, algorithm2, data);
        } else {
            cerr << "Error: Invalid number of arguments for Comparison mode!" << endl;
            printUsage();
            return 1;
        }
    }

    return 0;
}
