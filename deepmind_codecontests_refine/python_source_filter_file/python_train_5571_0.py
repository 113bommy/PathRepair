import sys

n = int(input())

a = [int(x) for x in input().split()]

l,r,k = 0, 0, 0
ans = 0
mmax, mmin = 0, 0

while r < n:
    if a[r] < a[mmin]:
        mmin = r
    elif a[r] > a[mmax]:
        mmax = r
    if abs(a[mmax] - a[mmin]) <= 1:
        ans = max(ans, r-l+1)
        r += 1
    else:
        if mmin > mmax:
            l = mmax + 1
            mmax = l
        else:
            l = mmin + 1
            mmin = l
    
print(ans)


