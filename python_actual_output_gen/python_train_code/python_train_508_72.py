N, X = map(int, input().split())
m = [int(input()) for i in range(N)]
print(N + int((N - sum(m))/min(m)))