t = int(input())
for tt in range(t):
    n, k, d = map(int, input().split())
    minkol = n
    a = list(map(int, input().split()))
    for i in range(n-d+1):
        kol = len(set(a[i:d+i]))
        if kol<minkol:
            minkol = kol
print(minkol)
