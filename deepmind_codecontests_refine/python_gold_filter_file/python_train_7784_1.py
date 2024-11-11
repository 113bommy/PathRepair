N, M = map(int, input().split())
if N % 2 != 0:
    for i in range(M):
        print(1+i, N-i)
elif N // 4 > M:
    for i in range(M):
        print(1+i, N-i)
else:
    for i in range(N//4):
        print(1+i, N-i)
    for i in range(N//4, M):
        print(1+i, N-i-1)