def f(a, x):
    n = len(a)
    res = 0
    for i in range(n):
        res+=a[i]**(n-i-1)
    return res


n, bx=map(int, input().split())
a = list(map(int, input().split()))
res1=f(a, bx)
n, bx=map(int, input().split())
a = list(map(int, input().split()))
res2=f(a, bx)
if res1==res2:
    print('=')
elif res1>res2:
    print('>')
else:
    print('<')