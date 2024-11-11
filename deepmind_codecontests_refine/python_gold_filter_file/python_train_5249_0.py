n, m, k = (int(s) for s in input().split())
a = [int(s) for s in input().split()]
x, y = a.count(1), a.count(2)
m -= x
k -= y
if m > 0:
    k += m
print(max(-m, 0) + max(-k, 0))
