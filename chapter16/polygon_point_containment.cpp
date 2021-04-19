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

typedef vector<Point> Polygon;

int contains(Polygon g, Point p)
{
  int n = g.size();
  bool x = false;
  for (int i = 0; i < n; ++i)
  {
    Point a = g[i] - p;
    Point b = g[(i + 1) % n] - p;
    if (abs(cross(a, b)) < EPS && dot(a, b) < EPS)
    {
      return 1;
    }
    if (a.y > b.y)
    {
      swap(a, b);
    }
    if (a.y < EPS && EPS < b.y && cross(a, b) > EPS)
    {
      x = !x;
    }
  }
  return (x ? 2 : 0);
}

int main()
{
  int n, q;
  cin >> n;
  Polygon g;
  Point tmp, p;
  for (int i = 0; i < n; ++i)
  {
    cin >> tmp.x >> tmp.y;
    g.push_back(tmp);
  }
  cin >> q;
  for (int i = 0; i < q; ++i)
  {
    cin >> p.x >> p.y;
    cout << contains(g, p) << endl;
  }

  return 0;
}
