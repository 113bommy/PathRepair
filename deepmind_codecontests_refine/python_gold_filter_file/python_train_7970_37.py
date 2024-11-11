def kol_re(n,m):
    minut = 240 - m
    k = 0
    for i in range(1,n+1):
        if minut - (5 * i) < 0:
            return k
        minut -= 5 * i
        k += 1
    return k
n,m = map(int,input().split())
print(kol_re(n,m))     