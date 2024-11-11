X, Y = map(int, input().split())

k = len(bin(int(Y/X))[2:])
print(k)