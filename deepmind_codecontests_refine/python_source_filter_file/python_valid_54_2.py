mod = 10**9 + 7

def odd(k):
    if k==0:
        return 1
    else:
        oddd = [1 for _ in range(k+1)]
        for a in range(k, 0, -1):
            if a==k:
                oddd[a] = (tno+1)%mod
            else:
                oddd[a] = ((tno+1)*oddd[a+1])%mod
        return oddd[1]

def even(k):
    if k==0:
        return 1
    else:
        eveen = [1 for _ in range(k+1)]
        for a in range(k, 0, -1):
            if a==k:
                eveen[a] = tno
            else:
                eveen[a] = (tro[a]+(tno-1)*eveen[a+1])%mod
        return eveen[1]

for _ in range(int(input())):
    n, k = map(int, input().split())
    tno = 2**(n-1)%mod
    tnt = 2*tno
    tro = [0 for _ in range(k+1)]
    pip = tnt
    for a in range(k, 0, -1):
        tro[a] = pip
        pip = pip*tnt%mod
    if n%2!=0:
        print(odd(k))
    else:
        print(even(k))