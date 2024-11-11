t = int(input())
for i in range(t):
    b = ''
    n = int(input())
    a = list(map(int, input().split()))
    for j in range(0, n, 2):
        b += str(a[j]) + ' ' + str(-a[j + 1]) + ' '
    b = b[:len(b) - 1]
    print(b)
