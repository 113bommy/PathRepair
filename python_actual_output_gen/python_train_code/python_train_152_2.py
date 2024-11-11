def gcd (a,b):
    while b:
        a %= b
        a,b = b,a
    return a

n = int(input())
a = list(map(int,input().split()))
m = max(a)
ost = sum([m-a[i] for i in range(n)])
if ost != 0:
    tmp = a[0]
    for i in range(1,n):
        tmp = gcd(tmp,a[i])
    if tmp == 1:
        if n==2: print(tmp, ost)
        else: print(ost,tmp)
    else:
        print(ost//tmp, tmp)
else: print(0,0)
