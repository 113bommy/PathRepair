s1 = input().split()
s2 = input().split()
n, s = int(s1[0]), int(s1[1])
a = []
for x in s2:
    a.append(int(x))
a.sort()
m = (n - 1) // 2
ans = abs(s - a[m])
if a[m] < s:
    for i in range(m + 1, n):
        if a[i] < s:
            ans += (s - a[i])
else:
    for i in range(m + 1, n):
        if a[i] > s:
            ans += (a[i] - s)
print(ans)