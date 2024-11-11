n, s = map(int, input().split())
a = [int(el) for el in input().split()]
b = [int(el) for el in input().split()]
for i in range(n):
    if a[i] == b[i] == 1:
        break
else:
    b[s - 1] = 0
if a[0] and (a[s - 1] or b[s - 1]):
    print('YES')
else:
    print('NO')
