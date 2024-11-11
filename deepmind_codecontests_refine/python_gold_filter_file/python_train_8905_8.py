n = int(input())
st = 2
def sqrt(x):
    lo = 0
    hi = 1000000000000
    while (lo < hi):
        mid = (lo + hi) // 2
        if mid*mid < x:
            lo = mid + 1
        else:
            hi = mid
    return lo

for i in range(1, n+1):
    a = ((i*(i+1))**2-st)/i
    a = int(a)
    print(a)
    st += i*a
    st = sqrt(st)