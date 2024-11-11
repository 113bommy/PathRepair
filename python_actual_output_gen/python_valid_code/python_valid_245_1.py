n, m = map(int, input().split())

gs = set()
for i in range(n):
    row = input()

    for j in range(m):
        if row[j] == 'G':
            g = j

        if row[j] == 'S':
            s = j

    if s > g:
        gs.add(g)
    else:
        print(-1)
        exit(0)

print(len(gs))


