n = int(input())
b = list(map(int, input().split()))
a = []
for i in b:
    if len(a) == 0:
        a.append(0)
        a.append(i)
    else:
        y = min(i - a[-2], a[-1])
        x = i - y
        a.append(x)
        a.append(y)
print(*a[::2], *a[::-1][::2])
