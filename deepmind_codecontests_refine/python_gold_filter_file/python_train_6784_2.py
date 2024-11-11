a = input()
b = input()
x = 0
s = 0

for i in range(len(b)):
    if a[i] != b[i]:
        x += 1

if not x % 2:
    s += 1

for i in range(len(b), len(a)):
    if a[i] != a[i - len(b)]:
        x += 1
    if not x % 2:
        s += 1

print(s)