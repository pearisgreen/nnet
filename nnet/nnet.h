#pragma once

#include <vector>
#include <iostream>

#include "mstd.h"
#include "vmath.h"

#include <vector>

using Math::Vec;
using Math::Mat;
using std::vector;

namespace ML {
  //in_nodes := amount of input nodes
  //nodes    := amount of nodes in layer
  struct Layer {
    Mat<u64> w;
    Vec<u64> b;
    Vec<u64> a;

    Layer(uint in_nodes, uint nodes);
    Layer(uint in_nodes, uint nodes, u64 *buffer);
    Vec<u64> *get_active(Vec<u64> &input);
  };

  struct Nnet_Structure : public vector<uint> {
    uint data_size();
    vector<Layer> *build(u64 *data);
    void load(FILE *file);
    void save(FILE *file);
  };

  struct Nnet {
    u64            *data;
    uint           data_size;
    Nnet_Structure structure;
    vector<Layer>  *lv;

    Nnet(Nnet_Structure _structure);
    Nnet(string &path);
    ~Nnet();

    Vec<u64> *get_output(Vec<u64> &in);

    void load(FILE *file);
    void save(FILE *file);
  };

  u64 cost(Vec<u64> &v, Vec<u64> &exp);

  std::ostream &operator<<(std::ostream &os, Layer &l);
  std::ostream &operator<<(std::ostream& os, Nnet &n);
}
