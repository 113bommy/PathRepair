n, k = map(int, input().split())
s = input()
l = []
for i in range(n):
    l.append(s[i])
l.sort()
c = 1
m = 1
for i in range(n - 1):
    if l[i] == l[i + 1]:
        c += 1
    else:
        if c > m:
            m = c
        c = 0
if c > m:
    m = c
if m > k:
    print("NO")
else:
    print("YES")