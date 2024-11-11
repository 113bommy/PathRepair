s = 1
n = int(input())
while s <= n:
    print((5 - s) // 2 * '*' + s * 'D' + (5 - s) // 2 * '*')
    s += 2
s = n - 2
while s > 0:
    print((5 - s) // 2 * '*' + s * 'D' + (5 - s) // 2 * '*')
    s -= 2    