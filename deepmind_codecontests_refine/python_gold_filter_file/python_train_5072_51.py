n, B = list(map(int, input().split(" ")))
a = list(map(int, input().split(" ")))

r = []
s = 0
for i in range(0, n):
    if a[i] % 2 == 0:
        s += 1
    else:
        s -= 1
    if i != 0 and i != n - 1 and s == 0:
        r.append([abs(a[i] - a[i + 1]), i])
        s = 0

res = 0
for i in sorted(r):
    if B - i[0] >= 0:
        B -= i[0]
        res += 1
    else:
        break

print(res)
