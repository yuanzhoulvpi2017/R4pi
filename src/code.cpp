#include <cpp11.hpp>
#include <stdio.h>
#include <iostream>

void calculate_p_fill(double &pi_result, int sample_n)
{
  R_xlen_t size = sample_n;

  // for (R_xlen_t i = 1; i <= size; ++i)
  // {
  //   x[i] = value;
  // }

  double x, y, radius_squared, pi;
  int within_circle = 0;

  for (int i = 0; i < size; i++)
  {
    x = (double)rand() / RAND_MAX;
    y = (double)rand() / RAND_MAX;

    radius_squared = x * x + y * y;

    if (radius_squared <= 1)
    {
      within_circle += 1;
    }
  }

  pi = (double)within_circle / size * 4;

  // std::cout << "the pi is : " << pi << std::endl;
  pi_result = pi;
}

[[cpp11::register]] double calculate_p_init(int sample_n)
{
  // R_xlen_t c_size = static_cast<R_xlen_t>(size[0]);
  // R_xlen_t c_size = 1;
  // cpp11::writable::doubles out(c_size);
  double out = 0.0;

  calculate_p_fill(out, sample_n);
  return out;
}
