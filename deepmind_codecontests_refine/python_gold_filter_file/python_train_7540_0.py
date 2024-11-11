N = int(2e3+3)
n = int(input())
a = list(map(int, input().split()))
maxi, mini = N//2, N//2
res = [[' '] * N for i in range(N)]
x, y = N//2, 0
for i in range(n):
    if i % 2 == 0:
        for j in range(a[i]):
            res[x][y] = '/'
            x -= 1
            y += 1
        x += 1
    else:
        for j in range(a[i]):
            res[x][y] = '\\'
            x += 1
            y += 1
        x -= 1
    maxi = max(maxi, x)
    mini = min(mini, x)
for i in range(mini, maxi+1):
    print(''.join(res[i][:y]))
