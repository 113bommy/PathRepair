n, a = int(input()), input()
u = a.count('5')
v = n - u
if not v:
    print(-1)
else:
    print('5' * (u // 9 * 9) + '0' * v)
