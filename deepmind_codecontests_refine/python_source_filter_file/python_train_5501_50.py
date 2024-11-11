N, M, K = map(int, input().split())

for n in range(N):
    for m in range(M):
        if K == n*(M-m) + (N-n)*m:
            print("Yes")
            exit()
print("No")