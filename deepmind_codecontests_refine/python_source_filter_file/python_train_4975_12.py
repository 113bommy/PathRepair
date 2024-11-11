#!/usr/bin/env python3
import sys, math, itertools, collections, bisect
input = lambda: sys.stdin.buffer.readline().rstrip().decode('utf-8')
inf = float('inf') ;mod = 10**9+7
mans = inf ;ans = 0 ;count = 0 ;pro = 1
sys.setrecursionlimit(10**7)

n = int(input())
G = [[] for i in range(n)]
for _ in range(n-1):
  a,b = map(int,input().split())
  a -= 1; b-=1
  G[a].append(b)
  G[b].append(a)
ans = [0] * n
color = [[],[]]
def coloring(node,pre,oddeven):
  color[oddeven%2].append(node)
  for vi in G[node]:
    if vi != pre:
      coloring(vi,node,oddeven+1)
  return

coloring(0,-1,0)
A = n//3 + int(bool(n%3))
B = n//3 + int(n%3 == 2)
C = n//3
# この時点ではA>=Bである
if len(color[0]) < len(color[1]):
  A,B = B,A
a=b=0; c=1
if len(color[0]) > C and len(color[1]) > C:
  for i,ci in enumerate(color[0]):
    if i < A:
      ans[ci] = 3 * i + 1
    else:
      ans[ci] = 3 * c
      c += 1

  for i,ci in enumerate(color[1]):
    if i < B:
      ans[ci] = 3 * i + 2
    else:
      ans[ci] = 3 * c
      c += 1

elif len(color[0]) <= C:
  # elseが読まれるとき必ずlen(color[0]) < A
  # Bは条件を満たすはず
  for i ,ci in enumerate(color[0]):
    ans[ci] = 3 * c
    c += 1
  for i ,ci in enumerate(color[1]):
    if a < A:
      ans[ci] = 3 * a + 1
      a += 1
    elif b < B:
      ans[ci] = 3 * b + 2
      b += 1
    else:
      ans[ci] = 3 * c
      c += 1

else:
  # elseが読まれるとき必ずlen(color[0]) < A
  # そんなことなかったwwww
  for i ,ci in enumerate(color[1]):
    ans[ci] = 3 * c
    c += 1
  for i ,ci in enumerate(color[0]):
    if a < A:
      ans[ci] = 3 * a + 1
      a += 1
    elif b < B:
      ans[ci] = 3 * b + 2
      b += 1
    else:
      ans[ci] = 3 * c
      c += 1

print(*ans)