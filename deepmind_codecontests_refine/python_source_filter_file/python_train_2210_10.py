import math

n = int(input())
a = [int(x) for x in input().split()]
res = (a.count(0)*a.count(0)-1) // 2
for i in range(1, 11):
    res += a.count(i) * a.count(-i)
print(res)
