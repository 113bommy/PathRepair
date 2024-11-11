n = int(input())
a = list(map(int, input().split()))
res = 0

m = 1000000001

for i in range(n-1, 0, -1):
  m = max(0, min(m-1, a[i]))
  res += m
print(res)
