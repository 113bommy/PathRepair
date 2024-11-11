import heapq

n = int(input())
a = [int(input()) for _ in range(n)]
m1, m2 = heapq.nlargest(2, a)
for ai in a:
  print(ai if ai != m1 else m2)
