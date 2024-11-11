S = int(input())
M = 10**9
y = M - (S % M)
x = int((S + y) / M)
print(0, 0, 1, M, x, y)
