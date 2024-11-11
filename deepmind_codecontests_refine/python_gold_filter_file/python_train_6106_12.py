n = int(input())
a = input().split()
b = input()
_b = list()

for i in range(len(a)):
    a[i] = int(a[i])

for l in b:
    _b.append(int(l))

b = _b
r = 10**9
l = -10**9

for i in range(len(b)):
    if i > 3:
        if b[i] == 0 and b[i-1] == b[i-2] == b[i-3] == b[i-4] == 1:
            if min(a[i], a[i-1], a[i-2], a[i-3], a[i-4]) - 1 < r:
                r = min(a[i], a[i-1], a[i-2], a[i-3], a[i-4]) - 1
        elif b[i] == 1 and b[i-1] == b[i-2] == b[i-3] == b[i-4] == 0:
            if max(a[i], a[i-1], a[i-2], a[i-3], a[i-4]) + 1 > l:
                l = max(a[i], a[i-1], a[i-2], a[i-3], a[i-4]) + 1

print(l, r)
