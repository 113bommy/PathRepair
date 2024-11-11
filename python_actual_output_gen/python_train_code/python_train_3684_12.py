n, x = [int(i) for i in input().split()]
A = [int(i) for i in input().split()]
A.sort()
taken = [0]*n

lo = 0
hi = n//2 + 1

def check(sz):
    if sz>n//2:
        return 0
    left = A[:sz]
    right = A[-sz:]
    ok = 1
    for i in range(len(left)):
        if right[i] - left[i] >= x:
            continue
        else:
            ok = 0
    return ok

for i in range(200):
    mid = (lo+hi)//2
    if check(mid):
        lo = mid
    else:
        hi = mid

ans = 0
for i in range(max(0, lo-5), min(hi+5, n//2)):
    if check(i):
        ans = i
    else:
        break

print(ans+1)
