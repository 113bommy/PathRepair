n, m = map(int, input().split(' '))
s = m % (n * (n + 1) // 2)
i = 0
while s >= i:
    s -= i
    i += 1
print(s)
