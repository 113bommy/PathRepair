N, L = [int(i) for i in input().split()]

t = L*(N-1) if L >= 0 else L*N if N+L >= 0 else L * N - (L+N-1)
print(N*(N-1)//2+t)