n, x = map(int, input().split())

a = list(map(int, input().split()))
a.sort()
c = 0

for i in range(a[-1]):
    if i not in a and i < x:
        c += 1
if x in a:
    c += 1
print(c)
