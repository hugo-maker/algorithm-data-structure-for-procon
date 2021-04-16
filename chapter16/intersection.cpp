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

double dot(Vector a, Vector b)
{
  return a.x * b.x + a.y * b.y;
}

double cross(Vector a, Vector b)
{
  return a.x * b.y - a.y * b.x;
}

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

bool intersect(Point p1, Point p2, Point p3, Point p4)
{
  return (ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 &&
          ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0);
}

bool intersect(Segment s1, Segment s2)
{
  return intersect(s1.p1, s1.p2, s2.p1, s2.p2);
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
    if (intersect(s1, s2))
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
