n = int(input())
a = list(map(int, input().split()))
m = sum(a)/n
d = 100
c = 0
for i in range(n):
  a[i] = abs(a[i] - m)
  if a[i] < d:
    d = a[i]
    c = i+1
print(c)