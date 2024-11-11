N, M, K = map(int, input().split())
for k in range(0,N+1):
    for l in range(0,M+1):
        if K == (k*(M - l) + (N - k)*l):
            print("Yes")
            quit()
print("No")
