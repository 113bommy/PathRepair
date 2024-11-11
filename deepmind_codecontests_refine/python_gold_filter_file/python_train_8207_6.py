x = int(input())
n0 = x // 11
n1 = (x - 11 * n0 + 5) // 6
print(2 * n0 + n1)