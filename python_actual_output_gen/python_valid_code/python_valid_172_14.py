x, y = list(map(int, input().split()))
b = ''
h = 0
for i in range(x):
    a = set(input())
    if len(a) > 1:
        print('NO')
        break
    else:
        a = list(a)
        b += a[0]
for d in range(len(b)-1):
            if int(b[d]) != int(b[d+1]):
                h += 1
if len(b) == x:
    if (h + 1) == y:
        print('YES')
    else:
        print('NO')