#include <iostream>
#include <stdexcept>
#include "segmentTree.hpp"
#include <sys/time.h>
#include <cstdlib>
#include <ctime>
#include <sys/resource.h>
using namespace std;
float diffUserTime(struct rusage *start, struct rusage *end) {
    return (end->ru_utime.tv_sec - start->ru_utime.tv_sec) +
           1e-6 * (end->ru_utime.tv_usec - start->ru_utime.tv_usec);
}

float diffSystemTime(struct rusage *start, struct rusage *end) {
    return (end->ru_stime.tv_sec - start->ru_stime.tv_sec) +
           1e-6 * (end->ru_stime.tv_usec - start->ru_stime.tv_usec);
}

double diffClockTime(struct timespec *start, struct timespec *end) {
    return (end->tv_sec - start->tv_sec) +
           1e-9 * (end->tv_nsec - start->tv_nsec);
}

int main(int argc, char *argv[]) {
    number segments, num_operations, target_segment, initial_instant = 0, final_instant = 0;
    auto p = Point(0, 0);
    cin >> segments >> num_operations;

    auto tree = SegmentTree(segments);

    struct rusage start, end;
    getrusage(RUSAGE_SELF, &start);

    struct timespec clockStart, clockEnd;
    clock_gettime(CLOCK_REALTIME, &clockStart);

    char operation;
    while (num_operations-- && cin >> operation) {
        if (operation == 'u') {
            auto matrix = Matrix();
            cin >> target_segment >> matrix;
//            tree.update(target_segment, matrix, 1, 0, segments - 1);
        } else if (operation == 'q') {
            cin >> initial_instant >> final_instant >> p;
            volatile auto a = p * tree.query(initial_instant, final_instant, 1, 0, segments - 1)
//            cout << p * tree.query(initial_instant, final_instant, 1, 0, segments - 1) << endl;
        } else throw invalid_argument(&"Invalid operation " [ operation]);
    }

    clock_gettime(CLOCK_REALTIME, &clockEnd);
    getrusage(RUSAGE_SELF, &end);

    std::cout  <<  diffClockTime(&clockStart, &clockEnd)  << std::endl;

}
