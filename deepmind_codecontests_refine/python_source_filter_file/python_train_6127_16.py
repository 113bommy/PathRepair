N, M = map(int, input().split())
if 2*N >= M:
    print(N)
else:
    print((2*N+M)//4)