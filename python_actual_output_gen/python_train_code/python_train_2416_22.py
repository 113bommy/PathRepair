x, y, z = map(int, input().split())
ans = x - y
a = []
if ans < 0:
    a.append('-')
elif ans == 0:
    a.append('0')
else:
    a.append('+')

for i in range(-z, z):
    if ans + i < 0:
        a.append('-')
    elif ans + i == 0:
        a.append('0')
    else:
        a.append('+')
a = list(set(a))
if len(a) > 1:
    print('?')
else:
    print(a[0])