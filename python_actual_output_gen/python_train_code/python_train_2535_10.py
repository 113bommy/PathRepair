s, a, b = [], 80, 0

for i in range(8):
    s.append(input())
for j in range(8):
    for i in range(8):
        if s[i][j] == 'W':
            a = min(a, i)
            break
        elif s[i][j] == 'B':
            break
    for i in range(7,-1,-1):
        if s[i][j] == 'B':
            b = max(b, i)
            break
        elif s[i][j] == 'W':
            break
if a < 7-b:
    print('A')
else:
    print('B')
