
n, m = map(int, input().split())
l = [[0 for col in range(2)]for row in range(m+1)]
maxx = 1
minn = n
for i in range(0, m):
    l[i][0], l[i][1] = map(int, input().split())
    if l[i][0] > l[i][1]:
        l[i][0], l[i][1] = l[i][1], l[i][0]
    maxx = max(l[i][0], maxx)
    minn = min(l[i][1], minn)

if minn < maxx:
    print(0)
else:
    print(minn-maxx)

