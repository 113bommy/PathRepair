N, M = map(int, input().split())
A = list(map(int, input().split())

s = sum(A)

print( max(N - A, -1) )