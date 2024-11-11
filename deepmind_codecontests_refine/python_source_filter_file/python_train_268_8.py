n,k,m = list(map(int, input().split()))
t = sorted(map(int, input().split()))
st = sum(t)
res = 0
for x in range(max(m//st, n)+1):
    rem = m-x*st
    m = x*(k+1)
    # for i in range(k):
        # y = min(rem//t[i], n-x)
        # rem -= t[i]*y
        # m += y
    for i in range(k):
        for _ in range(n-x):
            if rem >= t[i]:
                rem -= t[i]
                m += 1
    res = max(res, m)
print(res)