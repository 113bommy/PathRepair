from itertools import repeat

def line():
    return map(int, input().split())
def num():
    return int(input())
def nfunc(f, n, *args, **kwargs):
    return (f(*args, **kwargs) for _ in repeat(None, n))

t = num()
for _ in repeat(None, t):

    n,m = line()
    mems = list(line())
    uses = list(line())

    norms = sorted(mem for mem,use in zip(mems, uses) if use==1)[::-1]
    imps = sorted(mem for mem,use in zip(mems, uses) if use==2)[::-1]
    nn,ni = len(norms), len(imps)

    ans = 0
    i,j = 0,0
    while m>0:
        if i<nn-1 and j<ni:
            if m>norms[i] and norms[i]+norms[i+1] < imps[j]:
                ans += 2
                m -= imps[j]
                j += 1
            else:
                ans += 1
                m -= norms[i]
                i += 1
        elif i==nn-1 and j<ni:
            if m>norms[i] and norms[i]*2 < imps[j]:
                ans += 2
                m -= imps[j]
                j += 1
            else:
                ans += 1
                m -= norms[i]
                i += 1
        elif i<nn:
            ans += 1
            m -=norms[i]
            i += 1
        elif j<ni:
            ans += 2
            m -= imps[j]
            j += 1
        else:
            break
    if m>0:
        print(-1)
    else:
        print(ans)
