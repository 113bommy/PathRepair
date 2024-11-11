def f():
    n = int(input())
    s = input()
    rk = 1
    rs = s
    for k in range(1,n):
        if (n-k)%2:
            cur = s[k:]+s[:k][::-1]
        else:
            cur = s[k:]+s[:k]
        if cur < rs:
            rs = cur
            rk = k
    print(rs)
    print(rk+1)


t = int(input())
for i in range(t):
    f()