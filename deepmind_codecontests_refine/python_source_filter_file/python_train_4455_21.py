N, K = map(int, input().split())

print(((N*(N+1)*(N+2) - K*(K-1)*(3*N-2*K+4))/6 + N - K + 2)%1000000007)