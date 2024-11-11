import bisect
n = int(input())
colors = [-int(input())]
for _ in range(n-1):
    a = int(input())
    i = bisect.bisect_right(colors, -a)
    if i == len(colors):
        colors.append(-a)
    else:
        colors[i] = -a
print(len(colors))