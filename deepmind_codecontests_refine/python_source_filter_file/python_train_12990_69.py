A, B, N = map(int, input().split())
x = max(N, B-1)
print((A*x//B) - A*(x//B))