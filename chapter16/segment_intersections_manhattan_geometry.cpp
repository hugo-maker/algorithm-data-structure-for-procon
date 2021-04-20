#include <cmath>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <set>
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

static const int BOTTOM = 0;
static const int LEFT = 1;
static const int RIGHT = 2;
static const int TOP = 3;

class End_point
{
public:
  Point p;
  int seg, st;
  End_point() {}
  End_point(Point p, int seg, int st)
    : p(p), seg(seg), st(st) {}

  bool operator < (const End_point & ep) const
  {
    if (p.y == ep.p.y)
    {
      return st < ep.st;
    }
    else
    {
      return p.y < ep.p.y;
    }
  }
};

End_point EP[2 * 100000];

int manhattan_intersection(vector<Segment> S)
{
  int n = S.size();

  for (int i = 0, k = 0; i < n; ++i)
  {
    if (S[i].p1.y == S[i].p2.y)
    {
      if (S[i].p1.x > S[i].p2.x)
      {
        swap(S[i].p1, S[i].p2);
      }
    }
    else if (S[i].p1.y > S[i].p2.y)
    {
      swap(S[i].p1, S[i].p2);
    }

    if (S[i].p1.y == S[i].p2.y)
    {
      EP[k++] = End_point(S[i].p1, i, LEFT);
      EP[k++] = End_point(S[i].p2, i, RIGHT);
    }
    else
    {
      EP[k++] = End_point(S[i].p1, i, BOTTOM);
      EP[k++] = End_point(S[i].p2, i, TOP);
    }
  }

  sort(EP, EP + (2 * n));

  set<int> BT;
  BT.insert(1000000001);
  int cnt = 0;

  for (int i = 0; i < 2 * n; ++i)
  {
    if (EP[i].st == TOP)
    {
      BT.erase(EP[i].p.x);
    }
    else if (EP[i].st == BOTTOM)
    {
      BT.insert(EP[i].p.x);
    }
    else if (EP[i].st == LEFT)
    {
      set<int>::iterator b = BT.lower_bound(S[EP[i].seg].p1.x);
      set<int>::iterator e = BT.upper_bound(S[EP[i].seg].p2.x);
      cnt += distance(b, e);
    }
  }

  return cnt;
}

int main()
{
  int n;
  cin >> n;
  Segment tmp;
  vector<Segment> S;
  for (int i = 0; i < n; ++i)
  {
    cin >> tmp.p1.x >> tmp.p1.y >> tmp.p2.x >> tmp.p2.y;
    S.push_back(tmp);
  }

  cout << manhattan_intersection(S) << endl; 

  return 0;
}
