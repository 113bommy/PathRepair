a = input()
b = input()
f = 0
delta = 0
for i in range(len(b)):
    f += (a[i] != b[i])
    if i < len(a) - 1 and a[i] != a[i + 1]:
        delta += 1

ans = 0
f %= 2
ans = (f % 2 == 0)

for i in range(len(b), len(a)):
    f += (delta % 2)
    f %= 2
    ans += (f % 2 == 0)
    delta -= (a[i - len(b)] != a[i - len(b) + 1])
    if i < len(a) - 1:
        delta += (a[i + 1] != a[i])

print(ans)


