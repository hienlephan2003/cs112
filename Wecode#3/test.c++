#include <iostream>
#include <vector>
#include <set>

int main()
{
  std::vector<double> v = {0, 0, 1, 2, 3, 4, 0, 2};

  std::cout << "Number of unique elements is "
            << std::set<double>(v.begin(), v.end()).size()
            << std::endl;

  return 0;
}