n, m = map(int, input().split())
if (n//2) + (n % 2) <= m:
    _min = 0
else:
    _min = n - 2*m
tmp = 0
for i in range(n):
    if i*(i - 1) >= 2*m:
        tmp = i 
        break
_max = n - tmp
print(_min, _max)