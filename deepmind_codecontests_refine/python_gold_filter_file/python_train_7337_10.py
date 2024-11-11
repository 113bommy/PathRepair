n = int(input())
s = input()
a = []
for i in range(len(s)):
    if s[i] not in s[:i]:
        a.append(i)
if (len(a) < n):
    print('NO')
else:
    print('YES')
    for i in range(n - 1):
        print(s[a[i]: a[i + 1]])
    if (len(a)) >= n:
        print(s[a[n - 1]: len(s)])