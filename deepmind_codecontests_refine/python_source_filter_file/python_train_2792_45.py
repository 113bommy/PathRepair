N, M, D = map(int, input().split())

if D == 0:
    print(1/N*(M-1))
else:
    print(2(N-D)/N**2*(M-1))
