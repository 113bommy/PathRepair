n, a, b, c, d = map(int, input().split())
mis = min(a+b,b+d,c+d,c+a)
mas = max(a+b,b+d,c+d,c+a)
dif = mas-mis
res = 0
for x3 in range(1, n+1):
    res += n-dif
print(res)