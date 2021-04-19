#include <cmath>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cstdio>
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

static const int COUNTER_CLOCKWISE = 1;
static const int CLOCKWISE = -1;
static const int ONLINE_BACK = 2;
static const int ONLINE_FRONT = -2;
static const int ON_SEGMENT = 0;

int ccw(Point p0, Point p1, Point p2)
{
  Vector a = p1 - p0;
  Vector b = p2 - p0;
  if (cross(a, b) > EPS)
  {
    return COUNTER_CLOCKWISE;
  }
  if (cross(a, b) < -EPS)
  {
    return CLOCKWISE;
  }
  if (dot(a, b) < -EPS)
  {
    return ONLINE_BACK;
  }
  if (a.norm() < b.norm())
  {
    return ONLINE_FRONT;
  }

  return ON_SEGMENT;
}

Polygon andrew_scan(Polygon s)
{
  int n = s.size();
  int k = 0;
  if (n < 3)
  {
    return s;
  }
  sort(s.begin(), s.end());
  Polygon ret(2 * n);

  for (int i = 0; i < n; ret[k++] = s[i++])
  {
    while (k >= 2 && ccw(ret[k - 2], ret[k - 1], s[i]) == ON_SEGMENT ||
                     ccw(ret[k - 2], ret[k - 1], s[i]) == CLOCKWISE)
    {
      k--;
    }
  }
  for (int i = n - 2, t = k + 1; i >= 0; ret[k++] = s[i--])
  {
    while (k >= t && ccw(ret[k - 2], ret[k - 1], s[i]) == ON_SEGMENT ||
                     ccw(ret[k - 2], ret[k - 1], s[i]) == CLOCKWISE)
    {
      k--;
    }
  }
  ret.resize(k - 1);
  return ret;
}

int main()
{
  int n;
  cin >> n;
  Polygon s;
  int x, y;
  for (int i = 0; i < n; ++i)
  {
    cin >> x >> y;
    Point p(x, y);
    s.push_back(p);
  }

  Polygon ans = andrew_scan(s);
  printf("%d\n", int(ans.size()));
  for (auto p : ans)
  {
    printf("%d %d\n", int(p.x), int(p.y));
  }

  return 0;
}
