a = [[0] * 110] * 110
tc = eval(input())
while tc:
    tc -= 1
    n, m = map(int, input().split())
    for i in range(n):
        a[i] = [int(j) for j in input().split()]
        for j in range(m):
            if i + j & 1 != a[i][j] & 1:
                a[i][j] += 1
                print(a[i][j], end = " \n"[j == m - 1])
    