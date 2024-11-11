a = int(input())
b, c = a // 7, a // 7
b += [0, 1][a % 7 == 6]
c += [a % 7, 2][a % 7 > 2]
print("%d %d" % (b, c))
