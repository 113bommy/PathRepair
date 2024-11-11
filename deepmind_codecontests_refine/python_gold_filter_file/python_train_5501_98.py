N, M, K = map(int, input().split())


for a in range(N+1):
    for b in range(M+1):
        if b * (N-a) + a * (M-b) == K:
            print('Yes')
            exit()


print('No')