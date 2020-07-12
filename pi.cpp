#include <cmath>
#include <iostream>
#include <numeric>
using namespace std;

#define debug(_w_) (cout << #_w_ << " = " << _w_ << '\n')

typedef uint64_t l;

void run_calculation_v1() {
  // long double run_calculation_v1() {

  const l RADIUS = sqrt(double(numeric_limits<l>::max())) - 1;
  // const l RADIUS = sqrt(double(1ULL << 42)) - 1;

  const l RADIUS_SQUARED = RADIUS * RADIUS;

  // debug(RADIUS);
  // debug(RADIUS_SQUARED);

  l points_inside = 0;
  points_inside += RADIUS / 2 + 1;

  l x = 1;
  l y = RADIUS;
  l x_squared = x * x;
  l y_squared = y * y;

  const l LIMIT_X = l(double(RADIUS) * (sqrt(2.0) / 2.0));
  // debug(LIMIT_X);

  while (x <= LIMIT_X) {
    if (x_squared + y_squared <= RADIUS_SQUARED) {
      points_inside += y;
      x_squared += x + (x + 1);
      x++;
    } else {
      y_squared -= y + (y - 1);
      y--;
    }
  }

  points_inside -= (LIMIT_X / 2) * (LIMIT_X + 1);
  l all_points = RADIUS_SQUARED / 2;

  // debug(points_inside);
  // debug(all_points);

  long double result = (long double)points_inside / all_points * 4;
  printf("\n%.25Lf\n", result);
  printf("%.25lf\n", M_PI);

  // debug(points_inside);
  // debug(RADIUS_SQUARED / 2);

  // cout << points_inside << '\n';
  // cout << RADIUS_SQUARED << '\n';
  // cout << OUTSIDE << '\n';

  // cout << (long double)(points_inside) / OUTSIDE << '\n';

  // return (long double)(points_inside) / OUTSIDE * 8;
}

void run_calculation_v2() {
  // long double run_calculation_v1() {

  const l RADIUS = sqrt(double(numeric_limits<l>::max())) - 1;
  // const l RADIUS = sqrt(double(1ULL << 42)) - 1;

  const l RADIUS_SQUARED = RADIUS * RADIUS;

  // debug(RADIUS);
  // debug(RADIUS_SQUARED);

  l points_inside = 0;
  points_inside += RADIUS / 2 + 1;

  l x = 1;
  l y = RADIUS;
  l x_squared = x * x;
  l y_squared = y * y;

  l LIMIT_X = l(double(RADIUS) * (sqrt(2.0) / 2.0));
  LIMIT_X += LIMIT_X + 1;

  // debug(LIMIT_X);

  while (x <= LIMIT_X) {
    if (x_squared + y_squared <= RADIUS_SQUARED) {
      points_inside += y;
      x += 2;
      x_squared += x;
    } else {
      y_squared -= y + (y - 1);
      y--;
    }
  }

  points_inside -= (LIMIT_X / 2) * (LIMIT_X + 1);
  l all_points = RADIUS_SQUARED / 2;

  // debug(points_inside);
  // debug(all_points);

  long double result = (long double)points_inside / all_points * 4;
  printf("\n%.25Lf\n", result);
  printf("%.25lf\n", M_PI);
}

int main() { run_calculation_v2(); }