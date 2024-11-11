n, a = int(input()), input()
for i in range(n - 1):
    if a[i] > a[i + 1]:
        print('YES', i, i + 1)
        break
else:
    print('NO')