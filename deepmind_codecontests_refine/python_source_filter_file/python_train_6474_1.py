n, m = map(int, input().split())

def powerMod(base, exp):
    if exp == 0: return 1
    if exp == 1: return base
    ret = powerMod(base, exp//2)
    if exp % 2:        
        ret = (ret * ret * base) % 100000007
    else:
        ret = (ret * ret) % 100000007

    return ret
base = powerMod(2, m) - 1

ans = powerMod(base, n)
print(ans)
