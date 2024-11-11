n, k = map(int, input().split())
a = list(map(int, input().split()))


def check(x: int, s: int):
    global n, k, a
    res = s
    up = (k+(1 if(s == 0) else 0))//2
    i = s
    tag = 1
    while(i < n):
        if(a[i] <= x and tag == 1):
            tag = 0
            res += 1
        elif(tag == 0):
            tag = 1
            res += 1
        i += 1
    if(res >= k):
        return True
    else:
        return False


l, r = 0, 10**9+7
while(l+1 < r):
    mid = (l+r)//2
    if(check(mid, 0) or check(mid, 1)):
        r = mid
    else:
        l = mid
print(r)
