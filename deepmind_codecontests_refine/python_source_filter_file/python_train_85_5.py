n, m = map(int, input().split())
ab = [list(map(int, input().split())) for i in range(n)]
cd = [list(map(int, input().split())) for i in range(m)]
for i in ab:
    l = []
    for j in cd:
        l.append(abs((j[0] - i[0]) + (j[1] - i[1])))
    print(l.index(min(l)) + 1)