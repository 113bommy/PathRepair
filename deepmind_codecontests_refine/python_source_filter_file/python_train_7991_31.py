from math import ceil

N, K = map(int, input().split())
A = [*map(int, input().split())]

l_lb, l_min = 1, max(A)
while l_min - l_lb > 1:
  l_mid = (l_lb + l_min) // 2
  if sum(ceil(a/l_mid) for a in A) - N > K:
    l_lb = l_mid
  else:
    l_min = l_mid
print(l_min)