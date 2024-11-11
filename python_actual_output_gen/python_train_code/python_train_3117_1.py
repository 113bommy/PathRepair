x1, y1, r1 = map(int, input().split())
x2, y2, r2 = map(int, input().split())
sq = lambda x : x * x
dis = (sq(x1 - x2) + sq(y1 - y2))**0.5
def solve(L, r1, r2):
  if r1 < r2:
    r1, r2 = r2, r1
  if L >= r1 + r2:
    return L - r1 - r2
  elif L <= r1 - r2:
    return L + r2 - r1
  else:
    return 0
print(solve(dis, r1, r2) / 2)
