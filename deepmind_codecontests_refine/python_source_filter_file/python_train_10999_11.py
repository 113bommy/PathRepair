n = int(input())
l = []
for i in range(n):
    a, b = list(map(int, input().split()))
    l.append([a, b, i])




l.sort(key = lambda x: (x[0], -(x[1]), x[2]))
cur = l[0][1]
ind = 0
for i in range(1, n):
    if cur >= l[i][1]:
        print( l[i][2] + 1, ind + 1)
        exit()
    else:
        cur = l[i][1]
        ind = l[i][2]
print(-1, -1)