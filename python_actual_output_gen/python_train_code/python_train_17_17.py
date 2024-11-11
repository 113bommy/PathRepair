n = int(input())
a = []
res = 2
left = 0
for i in range(n):
    a.append(list(map(int, input().split())))
    if i == 0:
        left = a[i][0]
    if i > 1:
        if a[i-1][0] - left > a[i-1][1]:
            res += 1
            left = a[i-1][0]
        elif a[i][0] - a[i-1][0] > a[i-1][1]:
            res += 1
            left = a[i-1][0] + a[i-1][1]
        else:
            left = a[i-1][0]
print(res)
