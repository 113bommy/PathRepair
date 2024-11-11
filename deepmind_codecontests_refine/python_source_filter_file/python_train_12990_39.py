A,B,N = map(int,input().split())

n = min(N, A-1)
print(int(A*n/B) - A*int(n/B))