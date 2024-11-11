import sys;input=sys.stdin.readline
T, = map(int, input().split())
for _ in range(T):
    N, = map(int, input().split())
    X = list(map(int, input().split()))
    l = [-1] * N
    b = 0
    f = 1
    for i in range(N):
        x = X[i]
        if b > x:
            f = 0
            break
        b = x-b
        l[i] = b
    if f and b == 0:
        print("YES")
        continue
    l2 = [-1]*N
    b = 0
    for i in range(N-1, -1, -1):
        x = X[i]
        if b > x:
            break
        b = x-b
        l2[i] = b

    f = 0
    for i in range(N-1):
        c, b = X[i], X[i+1]
        if i==0:
            a = 0
        else:
            a = l[i-1]
        if i==N-2:
            d=0
        else:
            d = l2[i+2]
        if a==-1 or d==-1:
            continue
        if b-a==c-d and b>=a:
            print("YES")
            f=1
            break
    if not f:
        print("NO")


