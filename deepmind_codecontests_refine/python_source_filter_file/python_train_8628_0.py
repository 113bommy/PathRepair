n = int(input())
a = sorted(map(int,input().split()))
b = [(a[i + 1] - a[i], i) for i in range(n -1)]
b.sort(key = lambda x:x[0])
if b[0][1] < n - 2:print((a[-1] + a[-2]) / c)
elif b[0][1] == n - 3:
    if b[1][1] == n - 2:print(max((a[-1] + a[-2]) / b[2][0], (a[-1] + a[-4]) / b[0][0], (a[-3] + a[-4]) / b[1][0]))
    else:print(max((a[-1] + a[-2]) / b[1][0], (a[-1] + a[-4]) / b[0][0]))
else:
    if b[1][1] == n - 3:print(max((a[-1] + a[-2]) / b[2][0], (a[-1] + a[-4]) / b[1][0], (a[-3] + a[-4]) / b[0][0]))
    else:print(max((a[-1] + a[-2]) / b[1][0], (a[-3] + a[-4]) / b[0][0]))
