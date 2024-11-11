N, K=map(int,input().split())
print(((N+1)*(N+K+1)*(N-K+2)/2+N-K+2-(N+1)*(N+2)*(2*N+3)/6+(K-1)*K*(2*K-1)/6)%(10**9+7))