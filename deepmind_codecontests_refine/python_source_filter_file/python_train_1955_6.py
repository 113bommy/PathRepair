import sys
sys.stdin.readline

n = int(input())
a = []
for _ in range(n):
    sa = input().strip()
    tmp = 0
    for i in range(len(sa)):
        if sa[i] == '.':
            break
        tmp = tmp * 10 + int(sa[i])
    i += 1
    for j in range(i, i + 9):
        if j < len(sa):
            tmp = tmp * 10 + int(sa[j])
        else:
            tmp *= 10
    a.append(tmp)

div25 = [[0, 0] for _ in range(n)]
for i, _a in enumerate(a):
    while _a % 2 == 0:
        div25[i][0] += 1
        _a //= 2
    while _a % 5 == 0:
        div25[i][1] += 1
        _a //= 5

div25.sort(key=lambda x: (-x[1], -x[0]))

plot = [[0 for _ in range(50)] for _ in range(25)]
ans = 0
for d25 in div25:
    rem2, rem5 = max(0, 18 - d25[0]), max(0, 18 - d25[1])
    for j in range(rem5, 25):
        for k in range(rem2, 50):
            ans += plot[j][k]
    plot[d25[1]][d25[0]] += 1
print(ans)