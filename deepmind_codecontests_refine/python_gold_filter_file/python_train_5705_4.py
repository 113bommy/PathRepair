N, K = map(int, input().split())
for i in range(N):
    j = (N+(N+1)//2-i-1)%N
    k = N+(N+2*i)%N+(2*i>=N)*(N+1)%2
    if 2*K-1>N:
        print(-1)
        break
    print(j+K, k+K, 2*N+i+K)
