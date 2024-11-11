n = int(input())
a = []
ans = 0
for i in range(n - 1, n - 82, -1):
    if i == 0:
        break
    s = 0
    for z in range(len(str(i))):
        s += int(str(i)[z])
    if s + i == n:
        ans += 1
        a.append(i)
print(ans)
for i in range(len(a)):
    print(a[i])