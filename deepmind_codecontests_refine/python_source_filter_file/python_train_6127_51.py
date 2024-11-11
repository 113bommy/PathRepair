N, M = map(int, input().split())

res = 0
res += min(N, M//2)
M -= N*2

res += M//4

print(res)