N, M, K = map(int, input().split())
for k in range(1,N+1):
    for l in range(1,M+1):
        if K == (k*(M - l) + (N - k)*l):
            print("Yes")
            quit()
print("No")
