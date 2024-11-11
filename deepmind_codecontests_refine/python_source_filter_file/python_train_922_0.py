from itertools import combinations
from heapq import heappop, heappush
import sys
sys.setrecursionlimit(1000000)
INF = 10 ** 20

def convert(s, m, n):
  if s == "H":
    return 0
  if s == "D":
    return 1
  if s[0] == "C":
    return int(s[1]) + 1
  if s[0] == "L":
    return int(s[1]) + m + 1

def get_cost(start, m, n, edges):
  cost = [INF] * (m + n + 2)
  cost[start] = 0
  que = []
  heappush(que, (0, start))
  while que:
    total, node = heappop(que)
    for dist, to in edges[node]:
      if cost[to] > total + dist:
        cost[to] = total + dist
        #if not (2 <= to <= m + 1):
        heappush(que, (total + dist, to))
  return cost


def shortest_path(start, goal, rest, cakes_dist, dic):
  if not rest:
    return cakes_dist[start][goal]
  if (start, rest) in dic:
    return dic[(start, rest)]
  
  ret = INF
  for to in rest:
    ret = min(ret, shortest_path(to, goal, tuple((i for i in rest if i != to)), cakes_dist, dic) + cakes_dist[start][to])
  dic[(start, rest)] = ret
  return ret

while True:
  m, n, k, d = map(int, input().split())
  if m == 0:
    break
  clst = list(map(int, input().split()))
  """
  Home ... 0
  D ... 1
  Cake ... 2, 3, ... m + 1
  Land ... m + 2, m + 3, ... m + n + 1
  """
  edges = [[] for _ in range(m + n + 2)]
  for _ in range(d):
    s, t, e = input().split()
    e = int(e)
    s = convert(s, m, n)
    t = convert(t, m, n)
    edges[s].append((e, t))
    edges[t].append((e, s))
  
  cakes_dist = [[INF] * (m + 2) for _ in range(m + 2)]
  for start in range(m + 2):
    cost = get_cost(start, m, n, edges)
    for to in range(m + 2):
      if to != start:
        cakes_dist[start][to] = cost[to]
  
  """
  now ... 現在いる点
  rest ... 残りのめぐる点
  dic[(now, rest)] ... 現在いる点、残りの点をまわる時の最小距離
  dic[(now, rest)] = min(cakes_dist[now][to] + dic[(to, rest - to)] for to in rest)
  """
  dic = {}
  ans = INF
  cakes = [i for i in range(2, m + 2)]
  for num in range(m + 1):
    for rest in combinations(cakes, num):
      cal = sum([clst[i - 2] for i in rest])
      ans = min(ans, shortest_path(0, 1, rest, cakes_dist, dic) * k - cal)
  print(ans)
