n,m = map(int,input().split())
lim = int(1e+9+7)


def pat(r,t = lim):
    ans = 1
    for i in range(r):
        ans = (ans*(i+1))%t
    return ans%t

a = pat(n)
b = pat(m)

if abs(n-m) < 1:
    print((a*b*2)%lim)
elif abs(n-m) == 1:
    print((a*b)%lim)
else:
    print(0)