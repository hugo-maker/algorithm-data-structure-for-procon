#include <cmath>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
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
  Polygon u, l;
  if (s.size() < 3)
  {
    return s;
  }
  sort(s.begin(), s.end());
  u.push_back(s[0]);
  u.push_back(s[1]);
  l.push_back(s[s.size() - 1]);
  l.push_back(s[s.size() - 2]);

  for (int i = 2; i < s.size(); ++i)
  {
    for (int n = u.size(); n >= 2 && ccw(u[n - 2], u[n - 1], s[i]) == COUNTER_CLOCKWISE; --n)
    {
      u.pop_back();
    }
    u.push_back(s[i]);
  }

  for (int i = s.size() - 3; i >= 0; --i)
  {
    for (int n = l.size(); n >= 2 && ccw(l[n - 2], l[n - 1], s[i]) == COUNTER_CLOCKWISE; --n)
    {
      l.pop_back();
    }
    l.push_back(s[i]);
  }

  reverse(l.begin(), l.end());
  for (int i = u.size() - 2; i >= 1; --i)
  {
    l.push_back(u[i]);
  }

  return l;
}

int main()
{
  int n;
  cin >> n;
  Polygon s;
  Point tmp;
  for (int i = 0; i < n; ++i)
  {
    cin >> tmp.x >> tmp.y;
    s.push_back(tmp);
  }

  auto ans = andrew_scan(s);
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); ++i)
  {
    cout << ans[i].x << " " << ans[i].y << endl;
  }

  return 0;
}
