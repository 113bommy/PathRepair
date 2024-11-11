n, m = map(int, input().split())
a = [[] for i in range(m)]
for i in range(n):
    x = input().split()
    a[int(x[1]) - 1].append([x[2], x[0]])
for i in range(m):
    x = sorted(a[i], reverse=True)
    if len(x) == 2:
        print(' '.join([x[0][1], x[1][1]]))
        continue
    if x[1][0] > x[2][0]:
        print(' '.join([x[0][1], x[1][1]]))
    else:
        print('?')
