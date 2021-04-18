#include <cmath>
#include <iostream>
#include <vector>
#include <iomanip>
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

double norm(Vector a)
{
  return a.x * a.x + a.y * a.y;
}

double abs(Vector a)
{
  return sqrt(norm(a));
}

struct Segment
{
  Point p1, p2;
};

typedef Segment Line;

class Circle
{
public:
  Point c;
  double r;
  Circle(Point c = Point(), double r = 0.0)
    : c(c), r(r) {}
};

double dot(Vector a, Vector b)
{
  return a.x * b.x + a.y * b.y;
}

double cross(Vector a, Vector b)
{
  return a.x * b.y - a.y * b.x;
}

double get_distance_lp(Line l, Point p)
{
  return abs(cross(l.p2 - l.p1, p - l.p1) / abs(l.p2 - l.p1));
}

Point project(Segment s, Point p)
{
  Vector base = s.p2 - s.p1;
  double r = dot(p - s.p1, base) / norm(base);
  return s.p1 + base * r;
}

pair<Point, Point> get_cross_points(Circle c, Line l)
{
  Vector pr = project(l, c.c);
  Vector e = (l.p2 - l.p1) / abs(l.p2 - l.p1);
  double d = get_distance_lp(l, c.c);
  double base = sqrt(c.r * c.r - d * d);
  return make_pair(pr + e * base, pr - e * base);
}

int main()
{
  Circle c;
  Line l;
  cin >> c.c.x >> c.c.y >> c.r;
  int q;
  cin >> q;
  for (int i = 0; i < q; ++i)
  {
    cin >> l.p1.x >> l.p1.y >> l.p2.x >> l.p2.y;
    auto cross_points = get_cross_points(c, l);
    if (cross_points.first < cross_points.second) 
    {
      swap(cross_points.first, cross_points.second);
    }
    cout << setprecision(8) << cross_points.first.x << " " << cross_points.first.y 
      << " " <<  cross_points.second.x << " " << cross_points.second.y << endl;
  }

  return 0;
}
