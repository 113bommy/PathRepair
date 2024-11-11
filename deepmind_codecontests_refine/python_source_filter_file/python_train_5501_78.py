N, M, K = [int(_) for _ in input().split()]

for i in range(M):
    for j in range(N):
        if i *(M-j) + j *(N-i) == K:
            print("Yes")
            exit()
print("No")