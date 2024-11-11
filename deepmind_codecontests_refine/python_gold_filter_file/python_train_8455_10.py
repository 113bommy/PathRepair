import collections
t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    table = collections.defaultdict(list)
    table2 = collections.defaultdict(list)
    for x in a:
        table[x].append([len(table[j]) for j in range(1, 27)])
    for x in a[::-1]:
        table2[x].append([len(table2[j]) for j in range(1, 27)])

    ans = 0
    for x in table:
        ans = max(ans, len(table[x]))
    for x in table:  # a:center
        for y in range(26):
            if x == y+1:
                continue
            l, r = 0, 0
            L = len(table[x])
            while(l+r <= L-1):
                if table[x][l][y] == table2[x][r][y]:
                    ans = max(ans, table[x][l][y]*2 + L - l - r)
                    l += 1
                elif table[x][l][y] > table2[x][r][y]:
                    ans = max(ans, table2[x][r][y]*2 + L - l - r)
                    r += 1
                else:
                    ans = max(ans, table[x][l][y]*2 + L - l - r)
                    l += 1
                # print(t)
    print(ans)
