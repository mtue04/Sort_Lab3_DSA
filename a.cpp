#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

#include "Algorithms//sort.h"
#include "HelpFunction//DataGenerator.cpp"

using namespace std;

void printUsage() {
    cout << "Usage: [Execution file] -a [Algorithm] [Given input] [Output parameter(s)]\n"
         << "       [Execution file] -a [Algorithm] [Input size] [Input order] [Output parameter(s)]\n"
         << "       [Execution file] -a [Algorithm] [Input size] [Output parameter(s)]\n"
         << "       [Execution file] -c [Algorithm 1] [Algorithm 2] [Given input]\n"
         << "       [Execution file] -c [Algorithm 1] [Algorithm 2] [Input size] [Input order]\n";
}

void runSortingAlgorithm(const string& algorithm, int* data, int n, const string& outputParam, double &time, long long int &comparisons) {
    if (outputParam == "-time") {
        // Handle Time Complexity
        clock_t start = clock();

        if (algorithm == "selection-sort")
            selectionSortTime(data, n);
        else if (algorithm == "insertion-sort")
            insertionSortTime(data, n);
        else if (algorithm == "bubble-sort")
            bubbleSortTime(data, n);
        else if (algorithm == "shaker-sort")
            shakerSortTime(data, n);
        else if (algorithm == "shell-sort")
            shellSortTime(data, n);
        else if (algorithm == "heap-sort")
            heapSortTime(data, n);
        else if (algorithm == "merge-sort")
            mergeSortTime(data, 0, n - 1);
        else if (algorithm == "quick-sort")
            quickSortTime(data, 0, n - 1);
        else if (algorithm == "counting-sort")
            countingSortTime(data, n);
        else if (algorithm == "radix-sort")
            radixSortTime(data, n);
        else if (algorithm == "flash-sort")
            flashSortTime(data, n);
        else {
            cout << "Error: Invalid sorting algorithm specified!" << endl;
            return;
        }

        clock_t end = clock();
        time = static_cast<double>(end - start) / CLOCKS_PER_SEC;

    } else if (outputParam == "-comp") {
        // Handle Calculating Comparisons
        if (algorithm == "selection-sort")
            comparisons = selectionSortCompare(data, n);
        else if (algorithm == "insertion-sort")
            comparisons = insertionSortCompare(data, n);
        else if (algorithm == "bubble-sort")
            comparisons = bubbleSortCompare(data, n);
        else if (algorithm == "shaker-sort")
            comparisons = shakerSortCompare(data, n);
        else if (algorithm == "shell-sort")
            comparisons = shellSortCompare(data, n);
        else if (algorithm == "heap-sort")
            comparisons = heapSortCompare(data, n);
        else if (algorithm == "merge-sort")
            comparisons = mergeSortCompare(data, 0, n - 1);
        else if (algorithm == "quick-sort")
            comparisons = quickSortCompare(data, 0, n - 1);
        else if (algorithm == "counting-sort")
            comparisons = countingSortCompare(data, n);
        else if (algorithm == "radix-sort")
            comparisons = radixSortCompare(data, n);
        else if (algorithm == "flash-sort")
            comparisons = flashSortCompare(data, n);
        else {
            cout << "Error: Invalid sorting algorithm specified!" << endl;
            return;
        }
    } else if (outputParam == "-both") {
        // Handle Time Complexity
        clock_t start = clock();

        if (algorithm == "selection-sort")
            selectionSortTime(data, n);
        else if (algorithm == "insertion-sort")
            insertionSortTime(data, n);
        else if (algorithm == "bubble-sort")
            bubbleSortTime(data, n);
        else if (algorithm == "shaker-sort")
            shakerSortTime(data, n);
        else if (algorithm == "shell-sort")
            shellSortTime(data, n);
        else if (algorithm == "heap-sort")
            heapSortTime(data, n);
        else if (algorithm == "merge-sort")
            mergeSortTime(data, 0, n - 1);
        else if (algorithm == "quick-sort")
            quickSortTime(data, 0, n - 1);
        else if (algorithm == "counting-sort")
            countingSortTime(data, n);
        else if (algorithm == "radix-sort")
            radixSortTime(data, n);
        else if (algorithm == "flash-sort")
            flashSortTime(data, n);
        else {
            cout << "Error: Invalid sorting algorithm specified!" << endl;
            return;
        }

        clock_t end = clock();
        time = static_cast<double>(end - start) / CLOCKS_PER_SEC;

        // Handle Calculating Comparisons
        if (algorithm == "selection-sort")
            comparisons = selectionSortCompare(data, n);
        else if (algorithm == "insertion-sort")
            comparisons = insertionSortCompare(data, n);
        else if (algorithm == "bubble-sort")
            comparisons = bubbleSortCompare(data, n);
        else if (algorithm == "shaker-sort")
            comparisons = shakerSortCompare(data, n);
        else if (algorithm == "shell-sort")
            comparisons = shellSortCompare(data, n);
        else if (algorithm == "heap-sort")
            comparisons = heapSortCompare(data, n);
        else if (algorithm == "merge-sort")
            comparisons = mergeSortCompare(data, 0, n - 1);
        else if (algorithm == "quick-sort")
            comparisons = quickSortCompare(data, 0, n - 1);
        else if (algorithm == "counting-sort")
            comparisons = countingSortCompare(data, n);
        else if (algorithm == "radix-sort")
            comparisons = radixSortCompare(data, n);
        else if (algorithm == "flash-sort")
            comparisons = flashSortCompare(data, n);
        else {
            cout << "Error: Invalid sorting algorithm specified!" << endl;
            return;
        }
    }

    delete[] data;
}

// // Output
//     if (outputParam == "-time") {
//         cout << "Running Time: " << time << " seconds" << endl;
//     } else if (outputParam == "-comp") {
//         cout << "Number of Comparisons: " << comparisons << endl;
//     } else if (outputParam == "-both") {
//         cout << "Running Time: " << time << " seconds" << endl;
//         cout << "Number of Comparisons: " << comparisons << endl;
//     }

int main(int argc, char* argv[]) {
    // Wrong Syntax
    if (argc < 4 || (string(argv[1]) != "-a" && string(argv[1]) != "-c")) {
        cout << "Error: Wrong Syntax. Please follow ONE of these structures:" << endl;
        printUsage();
        return 0;
    }

    // Handle Algorithm Mode
    if (string(argv[1]) == "-a") {
        // Command 2 - Prototype: [Execution file] -a [Algorithm] [Input size] [Input order] [Output parameter(s)]
        if (argc == 6) {
            double time;
            long long int compare;
            int* data = new int[stoi(argv[3])];
            if (string(argv[4]) == "-rand")
                GenerateData(data, stoi(argv[3]), 0);   // Generate Random Data
            else if (string(argv[4]) == "-sorted")
                GenerateData(data, stoi(argv[3]), 1);   // Generate Sorted Data
            else if (string(argv[4]) == "-rev")
                GenerateData(data, stoi(argv[3]), 2);   // Generate Reverse Sorted Data
            else if (string(argv[4]) == "-nsorted")
                GenerateData(data, stoi(argv[3]), 3);   // Generate Nearly Sorted Data
            else {
                cout << "Error: Invalid input order specified!" << endl;
                delete[] data;
                return 0;
            }
            runSortingAlgorithm(argv[2], data, stoi(argv[3]), argv[5], time, compare);
            // Output

        } else if (argc == 5) {
            ifstream inputFile(argv[3]);
            // Command 1 - Prototype: [Execution file] -a [Algorithm] [Given input] [Output parameter(s)]
            if (inputFile.is_open()) {
                int n;
                int* data;
                double time;
                long long int compare;

                // Read the input data from the file
                inputFile >> n;
                data = new int[n];
                for (int i = 0; i < n; ++i) {
                    inputFile >> data[i];
                }
                inputFile.close();

                runSortingAlgorithm(argv[2], data, n, argv[4], time, compare);
                // Output

            // Command 3 - Prototype: [Execution file] -a [Algorithm] [Input size] [Output parameter(s)]
            } else {
                int* data = new int[stoi(argv[3])];
                double time;
                long long int compare;
                GenerateData(data, stoi(argv[3]), 0); // Generate Random Data
                runSortingAlgorithm(argv[2], data, stoi(argv[3]), argv[4], time, compare);
                // Output

            }
        } else {
            cout << "Error: Invalid number of arguments for algorithm mode!" << endl;
            printUsage();
            return 0;
        }
    } else if (string(argv[1]) == "-c") {
        // Command 4 - Prototype: [Execution file] -c [Algorithm 1] [Algorithm 2] [Given input]
        if (argc == 5) {
            int n;
            int* data;
            string filename = argv[4];

            // Read the input data from the file
            ifstream inputFile(filename);
            if (!inputFile.is_open()) {
                cout << "Error: Cannot open the input file." << endl;
                return 0;
            }
            inputFile >> n;
            data = new int[n];
            for (int i = 0; i < n; ++i) {
                inputFile >> data[i];
            }
            inputFile.close();

            int* data1 = new int[n];
            int* data2 = new int[n];
            for (int i = 0; i < n; ++i) {
                data1[i] = data[i];
                data2[i] = data[i];
            }

            double time1, time2;
            long long int compare1, compare2;
            runSortingAlgorithm(argv[2], data1, n, "-both", time1, compare1);
            runSortingAlgorithm(argv[3], data2, n, "-both", time2, compare2);

            // Output

        // Command 5 - Prototype: [Execution file] -c [Algorithm 1] [Algorithm 2] [Input size] [Input order]
        } else if (argc == 6) {
            // Generate Data
            int* data = new int[stoi(argv[4])];
            if (string(argv[5]) == "-rand")
                GenerateData(data, stoi(argv[4]), 0);   // Generate Random Data
            else if (string(argv[5]) == "-sorted")
                GenerateData(data, stoi(argv[4]), 1);   // Generate Sorted Data
            else if (string(argv[5]) == "-rev")
                GenerateData(data, stoi(argv[4]), 2);   // Generate Reverse Sorted Data
            else if (string(argv[5]) == "-nsorted")
                GenerateData(data, stoi(argv[4]), 3);   // Generate Nearly Sorted Data
            else {
                cout << "Error: Invalid input order specified!" << endl;
                delete[] data;
                return 0;
            }

            int* data1 = new int[stoi(argv[4])];
            int* data2 = new int[stoi(argv[4])];
            for (int i = 0; i < stoi(argv[4]); ++i) {
                data1[i] = data[i];
                data2[i] = data[i];
            }
            double time1, time2;
            long long int compare1, compare2;
            runSortingAlgorithm(argv[2], data1, stoi(argv[4]), "-both", time1, compare1);
            runSortingAlgorithm(argv[3], data2, stoi(argv[4]), "-both", time2, compare2);
            // Output

        } else {
            cout << "Error: Invalid number of arguments for comparison mode!" << endl;
            printUsage();
            return 0;
        }
    } else {
        cout << "Error: Wrong Syntax. Please follow ONE of these structures:" << endl;
        printUsage();
        return 0;
    }

    return 0;
}
