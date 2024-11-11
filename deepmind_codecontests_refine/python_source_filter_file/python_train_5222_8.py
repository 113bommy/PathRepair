n, h, m = input().split()
n, h, m = int(n), int(h), int(m)

s = {}

for i in range(m):
    l, r, x = input().split()
    l, r, x = int(l), int(r), int(x)
    for j in range(l-1, r):
        if j+1 not in s:
            s[j+1] = x ** 2
        elif s[j+1] > x ** 2:
            s[j+1] = x ** 2

for i in range(1, n):
    if i not in s:
        s[i] = h ** 2

total = 0

for i in s.values():
    total += i;

print(total)
