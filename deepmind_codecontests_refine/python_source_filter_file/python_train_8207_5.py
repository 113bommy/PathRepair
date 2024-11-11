x = int(input())
n0 = x // 11
n1 = (x - 11 * n0 + 4) // 5
print(2 * n0 + n1)