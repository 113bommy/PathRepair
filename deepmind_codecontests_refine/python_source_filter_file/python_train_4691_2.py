import math
n = int(input())
x = list(map(int, input().split()))
y = list(map(int, input().split()))

for p in range(1, 4):
 sum = 0
 for i in range(n):
  sum += math.fabs(x[i]-y[i])**p
 print(sum**(1/p))

a = []
for i in range(n):
 a.append(math.fabs(x[i]-y[i]))
a = a.sort()
print(a[n])