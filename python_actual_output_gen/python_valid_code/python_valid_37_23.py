N = int(input())
X = round(N / 1.08)
print(X if int(X * 1.08) == N else ':(')