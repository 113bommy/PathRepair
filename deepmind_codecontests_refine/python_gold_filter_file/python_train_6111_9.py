input()
X, Y = input().split(), input().split()
print(*filter(lambda x: x in Y, X))