k = int(input())
if k % 2 == 0:
    print('NO')
elif k == 1:
    print('YES\n2 1\n1 2')
else:
    print('YES')
    print(2 * (k + 2), k * (k + 2))
    print(1, k + 3)
    for i in range(2):
        x = i * (k + 2)
        print(x + k + 1, x + k + 2)
        for j in range(k - 1):
            print(x + 1, x + j + 2)
            print(x + j + 2, x + k + 1)
            print(x + j + 2, x + k + 2)
        for a in range(1, (k - 3) // 2 + 1):
            for b in range(k):
                print(x + 2 + b, x + 2 + (b + a) % (k - 3))