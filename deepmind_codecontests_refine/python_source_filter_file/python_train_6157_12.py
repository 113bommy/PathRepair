x1, y1 = map(int, input().split())
x2, y2 = map(int, input().split())
n = int(input())
s = input()
a = [(0, 0)]
for el in s:
    if el == 'U':
        a.append((a[-1][0], a[-1][1] + 1))
    elif el == 'D':
        a.append((a[-1][0], a[-1][1] - 1))
    elif el == 'R':
        a.append((a[-1][0] + 1, a[-1][1]))
    else:
        a.append((a[-1][0] - 1, a[-1][1]))

L = 0
R = 10 ** 9 + 7
while R - L > 1:
    m = (L + R) // 2
    d = a[-1][0] * (m // n) + a[m % n][0]
    e = a[-1][1] * (m // n) + a[m % n][1]
    t = (d, e)
    if abs(x2 - t[0] - x1) + abs(y2 - t[1] - y1) <= m:
        R = m
    else:
        L = m

if R == 10 ** 9 + 7:
    print(-1)
else:
    print(R)
