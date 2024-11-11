n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
c = 0
d = 0
for i in range(n):
  if b[i] > a[i]:
    c += (b[i] - a[i]) // 2
  else:
    d += a[i] - b[i]
print(['Yes', 'No'][c < d])