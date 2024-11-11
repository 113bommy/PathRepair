n = int(input())
r = [0] * n
d = [0] * n
for i in range(n):
    r[i], d[i] = map(int, input().split())
s = 0
a, b = float('infinity'), -float('infinity')
for i in range(n):
    if d[i] == 1:
        a = min(a, s)
    else:
        b = max(b, s)
    s += r[i]
ans = 1899 - b
if s >= float('infinity'):
    print('Infinity')
elif b >= a:
    print('Impossible')
else:
    print(ans + s)




