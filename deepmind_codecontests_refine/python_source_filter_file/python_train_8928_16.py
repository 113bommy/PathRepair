import sys
input = sys.stdin.readline
from collections import deque

def main():
  h, w, k = map(int, input().split())
  x1, y1, x2, y2 = map(lambda x:int(x)-1, input().split())
  v1 = x1*(w+1)+y1
  v2 = x2*(w+1)+y2
  C = "".join(input().rstrip()+"@" for _ in range(h))
  dist = tuple(-1 if c=="@" else 10**10 for c in C)
  ans = 0
  que = deque()
  que.append(v1)
  dist[v1] = 0
  while que:
    v = que.popleft()
    if v == v2:
      print(dist[v2])
      exit()
    d = dist[v]+1
    for dr in (-(w+1), -1, w+1, 1):
      for i in range(1, k+1):
        nv = v+dr*i
        if 0 <= nv < h*(w+1):
          if dist[nv] > d:
            dist[nv] = d
            que.append(nv)
          elif dist[nv] == d:
            continue
          else:
            break
        else:
          break
  print(-1)
if __name__ == "__main__":
  main()