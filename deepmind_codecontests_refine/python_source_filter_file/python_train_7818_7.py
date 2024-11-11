n, m = map(int, input().split())
res = [[(5001+i, i)] for i in range(n)]
for i in range(m):
    a, b = map(int, input().split())
    res[a-1].append((a, i+1))
    res[b-1].append((b, i+1))

for i in range(n):
    print(len(res[i]))
    for p in res[i]:
        print(*p)
