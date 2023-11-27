#include <iostream>
#include <stdexcept>
#include "segmentTree.hpp"
using namespace std;

using namespace std;

int main(int argc, char* argv[]) {
    number segments, num_operations, target_segment, initial_instant = 0, final_instant = 0;
    auto p = Point(0, 0);
    cin >> segments >> num_operations;

    auto tree = SegmentTree(segments);

    char operation;
    while (num_operations-- && cin >> operation) {
        if (operation == 'u') {
            auto matrix = Matrix();
            cin >>  target_segment >> matrix;
            tree.update(target_segment, matrix, 1, 0, segments - 1);
        }
        else if (operation == 'q') {
            cin >> initial_instant >> final_instant >> p;
            cout << p * tree.query(initial_instant, final_instant, 1, 0, segments - 1) << endl;
        }
        else throw invalid_argument("Invalid operation " + operation);
    }
}
