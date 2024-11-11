[n,m] = list(map(int,input().split()))
if m > n:
    print(-1)
else:
    x = ((n//2)//m)*m
    if x < n//2:
        x += m
    print(x)
    