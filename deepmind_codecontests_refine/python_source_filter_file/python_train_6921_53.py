n = int(input())
a = sorted(map(int, input().split()))
c = 0
t = 0
for i in range(n):
  if t <= a[i]:
    c += 1
  t += a[i]
print(c)