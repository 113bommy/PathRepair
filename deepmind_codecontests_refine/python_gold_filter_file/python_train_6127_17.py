N, M = map(int, input().split())
if 2*N >= M:
    print(M//2)
else:
    print((2*N+M)//4)