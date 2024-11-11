

from collections import defaultdict

def ncr(n, r, p):
    num = den = 1
    for i in range(r):
        num = (num * (n - i)) % p
        den = (den * (i + 1)) % p
    return (num * pow(den,
                      p - 2, p)) % p

t = int(input())
for _ in range(t):

    n,k = map(int,input().split())
    l = list(map(int,input().split()))
    l = list(set(l))
    l.sort()
    flag = 0
    k1 = 0
    ans = 0
    if len(l) == 1 and k == 1:
        print(1)
        continue
    fl = 0
    for i in range(len(l)):
        if k <= 1:
            fl = 1
            break
        if k1 == 0:
            ans+=1



        k1+=1
        k1%=k
        if k1 == 0 and flag == 0:
            k-=1
            flag = 1
    if fl == 1:
        print(-1)
        continue
    print(ans)



