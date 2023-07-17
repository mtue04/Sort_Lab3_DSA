#include <iostream>
#include <fstream>
#include <string>
#include <chrono>

#include "sort.h"
#include "HelpFunction\time.h"

using namespace std;

string sortingNames[11] = { "selection-sort", "insertion-sort", "bubble-sort", "shaker-sort",
                            "shell-sort", "heap-sort", "merge-sort", "quick-sort", "counting-sort",
                            "radix-sort", "flash-sort" };
                            
int main(int argc, char* argv[]) {
    if (argc < 4) {
        cout << "Usage: " << argv[0] << " -a [Algorithm] [Input size] [Input order] [Output parameter(s)]" << endl;
        return 1;
    }

    string mode = argv[1];
    string algorithm = argv[2];
    int inputSize = stoi(argv[3]);
    string inputOrder = argv[4];
    string outputParams = argv[5];

    if (mode == "-a") {
        // Algorithm Mode

        // TODO
    }
    else if (mode == "-c") {
        // Comparison Mode

        if (argc < 6) {
            cout << "Usage: " << argv[0] << " -c [Algorithm 1] [Algorithm 2] [Input size] [Input order] [Output parameter(s)]" << endl;
            return 1;
        }

        string algorithm2 = argv[6];

        // TODO
    }
    else {
        cout << "Invalid mode. Please use -a or -c." << endl;
        return 1;
    }

    return 0;
}
