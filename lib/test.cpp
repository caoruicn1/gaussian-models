#include "matrix.hpp"
#include <cassert>
#include <iostream>

int main(int argc, char *argv[]) {
  int sampleA[2][3] = {{1, 2, 3}, {4, 5, 6}};
  double meanA[1][3] = {{2.5, 3.5, 4.5}};
  auto m1 = Matrix(sampleA), mean1 = Matrix(meanA);
  assert(m1.mean() == mean1);
  double r1[2][3] = {{2.5, 3.5, 4.5}, {2.5, 3.5, 4.5}};
  auto rep1 = Matrix(r1);
  assert(mean1.repeat(2, 1) == rep1);
  double sub1[2][3] = {{-1.5, -1.5, -1.5}, {1.5, 1.5, 1.5}};
  assert((m1 - rep1) == Matrix(sub1));

  int meanB[3][1] = {{1}, {2}, {3}};
  int mB[1][1] = {{2}};
  assert(Matrix(meanB).mean() == Matrix(mB));
  int meanC[1][3] = {{1, 2, 3}};
  int mC[1][1] = {{2}};
  assert(Matrix(meanC).mean() == Matrix(mC));

  int tranA[3][2] = {{1, 4}, {2, 5}, {3, 6}};
  assert(m1.transpose() == Matrix(tranA));

  int mulA[3][3] = {{17, 22, 27}, {22, 29, 36}, {27, 36, 45}};
  assert(m1.transpose() * m1 == Matrix(mulA));

  int diag1[3][1] = {{1}, {2}, {3}};
  int mdiag1[3][3] = {{1, 0, 0}, {0, 2, 0}, {0, 0, 3}};
  assert(Matrix(diag1).diag() == Matrix(mdiag1));
  int mdiag2[3][7] = {{1, 2, 3, 4, 5, 6, 7},
                      {8, 9, 10, 11, 12, 13, 14},
                      {15, 16, 17, 18, 19, 20, 21}};
  int diag2[3][1] = {{1}, {9}, {17}};
  assert(Matrix(mdiag2).diag() == Matrix(diag2));
  int mdiag3[6][3] = {{1, 2, 3},    {4, 5, 6},    {7, 8, 9},
                      {10, 11, 12}, {13, 14, 15}, {16, 17, 18}};
  int diag3[3][1] = {{1}, {5}, {9}};
  assert(Matrix(mdiag3).diag() == Matrix(diag3));

  int mDet1[3][3] = {{1, 0, 2}, {-1, 5, 0}, {0, 3, -9}};
  int abs_mDet1[3][3] = {{1, 0, 2}, {1, 5, 0}, {0, 3, 9}};
  assert(Matrix(mDet1).determinant() == -51);
  assert(Matrix(mDet1).abs() == Matrix(abs_mDet1));

  int mDet2[3][3] = {{1, 2, 0}, {-1, 1, 1}, {1, 2, 3}};
  assert(Matrix(mDet2).determinant() == 9);
  int cF2[3][3] = {{1, 4, -3}, {-6, 3, -0}, {2, -1, 3}};
  assert(Matrix(mDet2).cofactor() == Matrix(cF2));
  int ident2[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
  assert((Matrix(mDet2).inverse() * Matrix(mDet2))->identity());
  int sumA[2][3] = {{1, 2, 3}, {4, 5, 6}}, sumB[2][3] = {{4, 5, 6}, {1, 2, 3}};
  int mSum1[2][3] = {{5, 7, 9}, {5, 7, 9}};
  int mSub1[2][3] = {{-3, -3, -3}, {3, 3, 3}};
  assert(Matrix(sumA) + Matrix(sumB) == Matrix(mSum1));
  assert(Matrix(sumA) - Matrix(sumB) == Matrix(mSub1));

  int listCols1[6][1] = {{1}, {4}, {2}, {5}, {3}, {6}};
  assert(m1.list_elems_by_position() == Matrix(listCols1));

  int doubleA[2][3] = {{2, 4, 6}, {8, 10, 12}};
  assert(m1.scalar(2) == Matrix(doubleA));
  int subA[2][3] = {{0, 1, 2}, {3, 4, 5}};
  assert(m1.subtract(1) == Matrix(subA));
  int addA[2][3] = {{2, 3, 4}, {5, 6, 7}};
  assert(m1.add(1) == Matrix(addA));
  int powA[2][3] = {{1, 4, 9}, {16, 25, 36}};
  assert(m1.power(2) == Matrix(powA));
  int sM[3][1] = {{1}, {2}, {3}};
  assert(Matrix(sM).sumValue() == 6);
  int fsM[3][2] = {{1, 2}, {3, 4}, {5, 6}};
  int singleM[1][1] = {{5}};
  assert(Matrix(singleM).value() == 5);

  // TODO: test set_position
  assert(m1.get_position(1) == 1);
  assert(m1.get_position(2) == 4);
  assert(m1.get_position(3) == 2);
  assert(m1.get_position(4) == 5);
  assert(m1.get_position(5) == 3);
  assert(m1.get_position(6) == 6);

  int pM1[3][3] = {{1, -1, -1}, {-1, 2, 0}, {-1, 0, 3}};
  int cM1[3][3] = {{1, -1, -1}, {0, 1, -1}, {0, 0, 1}};
  assert(Matrix(pM1).cholesky().matrix == Matrix(cM1));

  int nPD1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  assert(Matrix(nPD1).cholesky().error);

  int nPD2[3][3] = {{1, 2, 3}, {2, 3, 3}, {3, 3, 3}};
  assert(Matrix(nPD2).cholesky().error);

  int lT1[2][2] = {{1, 2}, {3, 4}};
  double lmT2[2][2] = {{std::log(1), std::log(2)}, {std::log(3), std::log(4)}};
  assert(Matrix(lT1).log() == Matrix(lmT2));

  int rebp1[1][4] = {{4, 7, 2, 5}};
  assert(Matrix(nPD1).row_elems_by_position(2, 5) == Matrix(rebp1));

  int setex[3][1] = {{1}, {4}, {8}};
  int exset[3][3] = {{0, 0, 3}, {4, 5, 0}, {7, 8, 9}};
  auto tempM = Matrix(nPD1);
  tempM.set_positions(std::make_shared<Matrix>(setex), 0);
  assert(tempM == Matrix(exset));

  int find1[3][1] = {{1}, {4}, {7}};
  assert(Matrix(nPD1).find_positions(4, false, false) == Matrix(find1));
  int find2[4][1] = {{1}, {2}, {4}, {7}};
  assert(Matrix(nPD1).find_positions(4, false, true) == Matrix(find2));
  int find3[5][1] = {{3}, {5}, {6}, {8}, {9}};
  assert(Matrix(nPD1).find_positions(4, true, false) == Matrix(find3));
  int find4[6][1] = {{2}, {3}, {5}, {6}, {8}, {9}};
  assert(Matrix(nPD1).find_positions(4, true, true) == Matrix(find4));

  int nPD3[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
  auto tmLSM = Matrix(nPD1);
  auto list = tmLSM.find_positions(4, false, false);
  int nPD4[3][3] = {{8, 7, 6}, {4, 5, 6}, {7, 8, 9}};
  tmLSM.set_positions(list, Matrix(nPD3).subtract(1));
  assert(tmLSM == Matrix(nPD4));
  tmLSM.set_positions(list, std::make_shared<Matrix>(nPD3), -1);
  assert(tmLSM == Matrix(nPD4));
  return 0;
}
