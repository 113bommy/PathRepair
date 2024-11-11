l, r = map(int, input().split())
c = ''
for i in range(l + 1, r):
    a = set()
    for j in str(i):
        a.add(j)
    if len(a) == len(str(i)):
        print(i)
        exit(0)

print(-1)
