//
// Created by daviaraujo on 26/11/23.
//

#ifndef SEGMENTTREE_HPP
#define SEGMENTTREE_HPP

#include "matrix.hpp"

class SegmentTree {

public:
    number segments;
    Matrix *tree;
    explicit SegmentTree(number segments);
    ~SegmentTree();
    Matrix update(number target_segment, Matrix matrix, number current_segment, number left, number right);
    Matrix query(number initial_segment, number last_segment, number current_segment, number left, number right);
};



#endif //SEGMENTTREE_HPP
