N, M, K = map(int, input().split())

for i in range(N):
    for j in range(M):
        if N*i + M*j - 2*i*j == K:
            print('Yes')
            exit()

print('No')