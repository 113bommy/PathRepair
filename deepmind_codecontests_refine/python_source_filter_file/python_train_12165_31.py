N,K = map(int,input().split())
ab = sorted([map(int,input().split()) for _ in [0]*N])
for a,b in ab:
    K -= b
    if K <= 0:
        print(a)
        break