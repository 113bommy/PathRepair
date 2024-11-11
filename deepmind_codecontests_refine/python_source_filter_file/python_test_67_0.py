def binom(x,y):
    if y == 2:
        return x * (x-1) / 2
    if y == 3:
        return x * (x-1) * (x-2) / 6

n,prob = map(float,input().split())
if prob == 0.0:
    print(0)
    exit()

n = int(n)

def p(m):
    ans = 0
    if n-m >= 2 and m >= 1:
        ans += m * (binom(n-m,2)) * .75

    if n-m >= 1 and m >= 2:
        ans += m * (m-1) * (n-m) / 2

    if m >= 3:
        ans += binom(m,3)
    
    if ans == binom(n,3):
        return 1.0

    return ans / binom(n,3)

lo,hi = 1.0, float(n)
if p(lo) >= prob:
    print(1)
    exit()

while lo+1 < hi:
    mid = (hi+lo) // 2
    case = p(float(mid))

    if case >= prob:
        hi = mid
    else:
        lo = mid

print(int(hi))
exit()
