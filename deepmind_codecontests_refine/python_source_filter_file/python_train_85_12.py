n, m = map(int,input().split())
ab = [list(map(int,input().split())) for _ in range(n)]
cd = [list(map(int,input().split())) for _ in range(m)]

result = []
for a, b in ab:
    tmp = []
    for c, d in cd:
        tmp.append(abs(a-c) + abs(c-d))
    result.append(tmp.index(min(tmp)) +1)
for ans in result:
    print(ans)
