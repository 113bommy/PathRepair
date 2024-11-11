n, m = map(int, input().split())
a = []
for i in range(n):
    b = list(input())
    a.append(b)

s = 0
z = 0
for i in range(n):
    if "S" not in a[i]:
        z += 1
        s += len(a[i])

for i in range(m):
    d = []
    for j in range(n):
        d.append(a[j][i])
    if "S" not in d:
        s += len(d)-z

print(s)