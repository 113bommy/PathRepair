n, x = map(int, input().split())
a, b = max(n-x,x),min(n-x,x)
res = a+b
while b!=0:
    q = a/b
    r = a%b
    res += (b*2)*q
    if (r==0):
        res -= b
    a, b = b, r

print(res)