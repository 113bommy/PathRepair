def bs():
    global n,k
    l = 1
    r = 2**n-1
    while l <= r:
        mid = (l+r) // 2
        if mid == k: return n
        if mid < k:
            l = mid
        else:
            r = mid
        n -= 1


n,k= map(int,input().split())
print(bs())
