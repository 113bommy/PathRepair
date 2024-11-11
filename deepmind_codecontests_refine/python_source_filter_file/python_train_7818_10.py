n, m = map(int, input().split())
j = 0
lis = [[] for i in range(n)]
for i in range(m):
    a, b = map(int, input().split())
    lis[a - 1].append(j + 1)
    lis[b - 1].append(j + 1)
    j += 1

for pos in range(n):
    if len(lis[pos]) > 0:
        print(len(lis[pos]))
        for i in lis[pos]:
            print(str(i), str(pos + 1))
    else:
        print(1)
        print(j, pos + 1)
        j += 1
