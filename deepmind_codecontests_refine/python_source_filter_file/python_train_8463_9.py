n, m = map(int, input().split())
line = [input() for i in range(n)]

a = n + 1
b = -1
x = 0
y = n

for i in range(n):
    for ii in range(m):
        if line[i][ii] == '*' and ii < a:
            a = ii
        if line[i][ii] == '*' and ii > b:
            b = ii
for i in range(n):
    if '*' in line[i]:
        x = i
        break
for i in range(n-1, -1, -1):
    if '*' in line[i]:
        y = i
        break

for i in range(x, y+1):
    print(line[i][a:b+1])
