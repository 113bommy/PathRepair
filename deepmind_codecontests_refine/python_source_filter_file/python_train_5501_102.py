N, M, K = map(int, input().split())


for a in range(N+1):
    for b in range(M+1):
        if a * (N-1) + b * (M-1) == K:
            print('Yes')
            exit()


print('No')