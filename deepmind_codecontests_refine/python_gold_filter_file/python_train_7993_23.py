def combination(n, a):
    mod = pow(10, 9)+7
    x, y = 1, 1
    for i in range(a):
        x = x * (n-i)%mod
        y = y * (a-i)%mod
    return x * pow(y, mod-2, mod)%mod

x, y = map(int, input().split())
n, m = (2*y - x)//3, (2*x - y)//3
if (x + y)%3 != 0 or (n < 0 or m < 0):
    print(0)
else:
    ans2 = combination(n+m, n)
    print(ans2)
