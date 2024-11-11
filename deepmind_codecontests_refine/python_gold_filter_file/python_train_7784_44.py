N, M = map(int, input().split())
if N%2==0:
    r = N
    f = True
    for i in range(M):
        if f and i*4+2 >= N:
            r -= 1
            f = False
        print(1+i, r)
        r -= 1
else:
    for i in range(M):
        print(1+i, N-i)
