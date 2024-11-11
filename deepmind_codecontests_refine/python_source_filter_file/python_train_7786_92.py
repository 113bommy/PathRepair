S = int(input())
M = 10**9
x = M - (S % M)
y = int((S + x) / M)
print(0, 0, 1, M, x, y)
