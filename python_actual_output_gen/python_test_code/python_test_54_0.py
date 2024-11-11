def s():
    [n,x] = list(map(int,input().split()))
    a = 0
    b = 1000
    for _ in range(n):
        t = list(map(int,input().split()))
        t.sort()
        a = max(a,t[0])
        b = min(b,t[1])
    if b<a:
        print(-1)
    else:
        print(0 if x < a and x > b else min(abs(a-x),abs(b-x)))
s()
