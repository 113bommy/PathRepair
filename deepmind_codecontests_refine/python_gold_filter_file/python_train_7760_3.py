def calc(c):
    if c >= 'a' and c <= 'z': return (ord(c) - ord('a'))
    return ord(c) - ord('A') + 26

n = int(input())
s = input()
was = [False] * 52
for i in range(n):
    was[calc(s[i])] = True
go = [[10 * n] * 52 for i in range(n)]
for i in range(n - 1, -1, -1):
    if i < n - 1:
        for j in range(52):
            go[i][j] = go[i + 1][j]
    go[i][calc(s[i])] = i;
res = 10 * n
for i in range(n):
    curRight = i
    for j in range(52):
        if was[j]:
            curRight = max(curRight, go[i][j])
    res = min(res, curRight - i + 1)
print(res)
