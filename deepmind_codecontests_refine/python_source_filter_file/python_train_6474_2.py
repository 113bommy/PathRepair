n, m = map(int, input().split())
M = 1000000007
x = (pow(2, m, M - 1) - 1 + M) % M
print(pow(x, n, M - 1))
