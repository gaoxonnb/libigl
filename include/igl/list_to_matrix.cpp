#include "list_to_matrix.h"

#include <cassert>
#include <cstdio>

#include <Eigen/Dense>

#include "max_size.h"
#include "min_size.h"
#define VERBOSE
#include "verbose.h"

template <typename T, class Mat>
IGL_INLINE bool igl::list_to_matrix(const std::vector<std::vector<T > > & V,Mat & M)
{
  // number of rows
  int m = V.size();
  if(m == 0)
  {
    fprintf(stderr,"Error: list_to_matrix() list is empty()\n");
    return false;
  }
  // number of columns
  int n = igl::min_size(V);
  if(n != igl::max_size(V))
  {
    fprintf(stderr,"Error: list_to_matrix()"
      " list elements are not all the same size\n");
    return false;
  }
  assert(n != -1);
  // Resize output
  M.resize(m,n);

  // Loop over rows
  for(int i = 0;i<m;i++)
  {
    // Loop over cols
    for(int j = 0;j<n;j++)
    {
      M(i,j) = V[i][j];
    }
  }

  return true;
}

template <typename T, class Mat>
IGL_INLINE bool igl::list_to_matrix(const std::vector<T > & V,Mat & M)
{
  // number of rows
  int m = V.size();
  if(m == 0)
  {
    fprintf(stderr,"Error: list_to_matrix() list is empty()\n");
    return false;
  }
  // Resize output
  M.resize(m,1);

  // Loop over rows
  for(int i = 0;i<m;i++)
  {
    M(i) = V[i];
  }

  return true;
}

#ifndef IGL_HEADER_ONLY
// Explicit template specialization
// generated by autoexplicit.sh
template bool igl::list_to_matrix<int, Eigen::PlainObjectBase<Eigen::Matrix<int, -1, -1, 0, -1, -1> > >(std::vector<std::vector<int, std::allocator<int> >, std::allocator<std::vector<int, std::allocator<int> > > > const&, Eigen::PlainObjectBase<Eigen::Matrix<int, -1, -1, 0, -1, -1> >&);
// generated by autoexplicit.sh
template bool igl::list_to_matrix<double, Eigen::PlainObjectBase<Eigen::Matrix<double, -1, -1, 0, -1, -1> > >(std::vector<std::vector<double, std::allocator<double> >, std::allocator<std::vector<double, std::allocator<double> > > > const&, Eigen::PlainObjectBase<Eigen::Matrix<double, -1, -1, 0, -1, -1> >&);
// generated by autoexplicit.sh
template bool igl::list_to_matrix<double, Eigen::PlainObjectBase<Eigen::Matrix<int, -1, -1, 0, -1, -1> > >(std::vector<std::vector<double, std::allocator<double> >, std::allocator<std::vector<double, std::allocator<double> > > > const&, Eigen::PlainObjectBase<Eigen::Matrix<int, -1, -1, 0, -1, -1> >&);
// generated by autoexplicit.sh
template bool igl::list_to_matrix<int, Eigen::Matrix<int, -1, -1, 0, -1, -1> >(std::vector<std::vector<int, std::allocator<int> >, std::allocator<std::vector<int, std::allocator<int> > > > const&, Eigen::Matrix<int, -1, -1, 0, -1, -1>&);
// generated by autoexplicit.sh
template bool igl::list_to_matrix<double, Eigen::Matrix<double, -1, -1, 0, -1, -1> >(std::vector<std::vector<double, std::allocator<double> >, std::allocator<std::vector<double, std::allocator<double> > > > const&, Eigen::Matrix<double, -1, -1, 0, -1, -1>&);
// generated by autoexplicit.sh
template bool igl::list_to_matrix<double, Eigen::Matrix<int, -1, -1, 0, -1, -1> >(std::vector<std::vector<double, std::allocator<double> >, std::allocator<std::vector<double, std::allocator<double> > > > const&, Eigen::Matrix<int, -1, -1, 0, -1, -1>&);
template bool igl::list_to_matrix<bool, Eigen::PlainObjectBase<Eigen::Matrix<int, -1, -1, 0, -1, -1> > >(std::vector<bool, std::allocator<bool> > const&, Eigen::PlainObjectBase<Eigen::Matrix<int, -1, -1, 0, -1, -1> >&);
template bool igl::list_to_matrix<bool, Eigen::PlainObjectBase<Eigen::Matrix<int, -1, -1, 0, -1, -1> > >(std::vector<std::vector<bool, std::allocator<bool> >, std::allocator<std::vector<bool, std::allocator<bool> > > > const&, Eigen::PlainObjectBase<Eigen::Matrix<int, -1, -1, 0, -1, -1> >&);
template bool igl::list_to_matrix<int, Eigen::PlainObjectBase<Eigen::Matrix<int, -1, -1, 0, -1, -1> > >(std::vector<int, std::allocator<int> > const&, Eigen::PlainObjectBase<Eigen::Matrix<int, -1, -1, 0, -1, -1> >&);
template bool igl::list_to_matrix<int, Eigen::Matrix<double, -1, -1, 0, -1, -1> >(std::vector<std::vector<int, std::allocator<int> >, std::allocator<std::vector<int, std::allocator<int> > > > const&, Eigen::Matrix<double, -1, -1, 0, -1, -1>&);
template bool igl::list_to_matrix<int, Eigen::Matrix<double, -1, -1, 0, -1, -1> >(std::vector<int, std::allocator<int> > const&, Eigen::Matrix<double, -1, -1, 0, -1, -1>&);
#endif
