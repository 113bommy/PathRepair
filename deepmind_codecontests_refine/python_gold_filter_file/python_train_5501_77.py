N, M, K = [int(_) for _ in input().split()]

for i in range(N+1):
    for j in range(M+1):
        if i *(M-j) + j *(N-i) == K:
            print("Yes")
            exit()
print("No")