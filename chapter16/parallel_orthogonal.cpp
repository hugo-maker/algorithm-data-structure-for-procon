#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
#define EPS (1e-10)
#define equals(a, b) (fabs((a) - (b)) < EPS)

class Point
{
public:
  double x, y;

  Point(double x = 0, double y = 0)
    : x(x), y(y) {}

  Point operator + (Point p)
  {
    return Point(x + p.x, y + p.y);
  }
  Point operator - (Point p)
  {
    return Point(x - p.x, y - p.y);
  }
  Point operator * (double a)
  {
    return Point(a * x, a * y);
  }
  Point operator / (double a)
  {
    return Point(a / x, a / y);
  }

  double abs()
  {
    return sqrt(norm());
  }
  double norm()
  {
    return x * x + y * y;
  }

  bool operator < (const Point & p) const
  {
    return x != p.x ? x < p.x : y < p.y;
  }

  bool operator == (const Point & p) const
  {
    return fabs(x - p.x) < EPS && fabs(y - p.y) < EPS;
  }
};

typedef Point Vector;

struct Segment
{
  Point p1, p2;
};

typedef Segment Line;

double dot(Vector a, Vector b)
{
  return a.x * b.x + a.y * b.y;
}

double cross(Vector a, Vector b)
{
  return a.x * b.y - a.y * b.x;
}

bool is_orthgonal(Vector a, Vector b)
{
  return equals(dot(a, b), 0.0);
}

bool is_orthgonal(Point a1, Point a2, Point b1, Point b2)
{
  return is_orthgonal(a1  - a2, b1 - b2);
}

bool is_orthgonal(Segment s1, Segment s2)
{
  return equals(dot(s1.p2 - s1.p1, s2.p2 - s2.p1), 0.0);
}

bool is_parallel(Vector a, Vector b)
{
  return equals(cross(a, b), 0.0);
}

bool is_parallel(Point a1, Point a2, Point b1, Point b2)
{
  return is_parallel(a1 - a2, b1 - b2);
}

bool is_parallel(Segment s1, Segment s2)
{
  return equals(cross(s1.p2 - s1.p1, s2.p2 - s2.p1), 0.0);
}

int main()
{
  int q;
  cin >> q;

  Segment s1, s2;

  for (int i = 0; i < q; ++i)
  {
    cin >> s1.p1.x >> s1.p1.y >> s1.p2.x >> s1.p2.y;
    cin >> s2.p1.x >> s2.p1.y >> s2.p2.x >> s2.p2.y;
    if (is_parallel(s1, s2))
    {
      cout << 2 << endl;
    }
    else if (is_orthgonal(s1, s2))
    {
      cout << 1 << endl;
    }
    else
    {
      cout << 0 << endl;
    }
  }

  return 0;
}
