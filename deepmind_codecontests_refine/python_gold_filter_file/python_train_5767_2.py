n, x0, y0, x1, y1 = map(int, input().split())
s = input()
if y0 > y1:
    a2 = 'S'
else:
    a2 = 'N'
if x0 > x1:
    a1 = 'W'
else:
    a1 = 'E'
ch, cv = abs(x0-x1), abs(y0-y1)
i = 0
while i < n and (ch > 0 or cv > 0):
    if s[i] == a1:
        ch -= 1
    elif s[i] == a2:
        cv -= 1
    i += 1
if cv > 0 or ch > 0:
    print(-1)
else:
    print(i)
