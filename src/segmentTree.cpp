//
// Created by daviaraujo on 26/11/23.
//

#include "segmentTree.hpp"

SegmentTree::SegmentTree(number segments) {
    this->segments = segments;
    this->tree = new Matrix[segments << 2];
}

SegmentTree::~SegmentTree() {
    delete[] this->tree;
}

Matrix SegmentTree::update(number target_segment, Matrix matrix, number current_segment, number left, number right) {
    if (target_segment < left || target_segment > right) return this->tree[current_segment];
    if (left == right) this->tree[current_segment] = matrix;
    else {
        number mid = (left + right) >> 1;
        this->tree[current_segment] = this->update(target_segment, matrix, current_segment << 1, left, mid)
                                      * this->update(target_segment, matrix, (current_segment << 1) + 1, mid + 1, right);
    }

    return this->tree[current_segment];
}

Matrix SegmentTree::query(number initial_segment, number last_segment, number current_segment, number left,
                          number right) {
    if (initial_segment > right || last_segment < left) return {};
    if (left >= initial_segment && right <= last_segment) return this->tree[current_segment];
    number mid = (left + right) >> 1;

    return this->query(initial_segment, last_segment, current_segment << 1, left, mid) *
           this->query(initial_segment, last_segment, (current_segment << 1)  + 1, mid + 1, right);
}
