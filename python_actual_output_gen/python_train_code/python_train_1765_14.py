n, k = map(int, input().split())
a = [int(i) for i in input().split()]
b = [int(i) for i in input().split()]
if a[0] == 1:
    if a[k - 1] == 1:
        print('YES')
        exit()
    if b[k - 1] != 1:
        print('NO')
        exit()
    for i in range(n):
        if a[i] == 1 and b[i] == 1:
            print('YES')
            exit()
print('NO')