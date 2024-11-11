n, m = map(int, input().split())
a = [int(i) for i in input().split()]
b = [int(i) for i in input().split()]
d = {}
for i in a:
    if (i not in d):
        d[i] = 0
    d[i] += 1
pair = []
for i in range(n):
    for j in range(m):
        pair.append([a[i], b[j]])
pair.sort(key = lambda x: x[0] * x[1])
i = -2
if d[pair[-1][0]] > 1:
    print(pair[-1][0] * pair[-1][1])
else:
    while pair[i][0] == pair[i + 1][0] and d[pair[i][0]] == 1:
        i -= 1
    print(pair[-i][0] * pair[-i][1])