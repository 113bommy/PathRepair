
def func(m):
    return m * (m + 1) // 2

def check(m, d):
    return func(m) >= d

for t in range(int(input())):
    a,b = map(int, input().split())
    d = abs(b-a)
    low = 0
    high = 1000000000
    ans = None
    while low <= high:
        mid = (low+high)//2
        if check(mid,d):
            ans = mid
            high = mid - 1
        else:
            low  = mid + 1
    if func(ans) % 2 != d % 2:
        ans += 1
    print(ans)