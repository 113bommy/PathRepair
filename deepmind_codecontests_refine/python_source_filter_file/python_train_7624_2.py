x = int(input())

if x < 1 or x > 100:
    exit()

r = [0 for i in range(x)]
s = [0 for i in range(x)]
d = [[0, 0] for i in range(x)]

for i in range(x):
    d[i][0], d[i][1] = map(int, input().split())
    if (d[i][0] < 1 or d[i][0] > 100) and (d[i][1] < 1 or d[i][1] > 100):
        exit()

for i in range(x):
    r[i] = min(max(d[i][0], (2 * d[i][1])), max(d[i][1], (2 * d[i][0])))
    s[i] = r[i] * r[i]
    print(s[i])