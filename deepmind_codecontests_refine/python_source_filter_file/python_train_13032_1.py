x, n = map(int, input().split())
m = 10**9 + 7
s = []
for i in range(2, int(x ** .5) + 1):
    if x % i == 0:
        s.append(i)
        while not x % i:
            x //= i
if not s:
    s.append(x)
ans = 1
for i in s:
    a = n
    res = 0
    while (a):
        a //= i
        res += a
    ans *= pow(i, res, m)
print(ans % m)