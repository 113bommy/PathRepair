a = list(input().split(' '))
n, k = int(a[0]), int(a[1])
for i in range(n):
    res = []
    for j in range(n):
        if i == j:
            print(k, end=' ')
        else:
            print(0, end=' ')
    print('\n', end = '')
