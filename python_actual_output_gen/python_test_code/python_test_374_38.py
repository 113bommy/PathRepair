n, s = int(input()), input()
x = s.count('z')
y = (n - 4 * x) // 3
print('1' * y + '0' * x)
