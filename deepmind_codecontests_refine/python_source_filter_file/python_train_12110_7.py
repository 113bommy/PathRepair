n, m = [int(i) for i in input().split()]
a = []
for i in range(n):
    a.append([int(j) for j in list(input().rstrip())])
if n == 1:
    print(m)
    exit(0)
cnt = set()
for j in range(m):
    t = [a[i][j] for i in range(n)]
    b = max(t)
    for i in range(n):
        if t[i] == b:
            cnt.add(i)
print(len(cnt))
