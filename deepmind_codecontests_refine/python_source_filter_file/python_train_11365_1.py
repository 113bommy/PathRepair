n = int(input())
s = input()

h = (n + 1) // 2

ans = pow(10, 100000) + 9

for i in range(h, n):
    if s[i] != '0':
        ans = min(ans, int(s[:i]) + int(s[i:]))
        break

for i in range(h, 0, -1):
    if s[i] != '0':
        ans = min(ans, int(s[:i]) + int(s[i:]))
        break
if h > 0:
    for i in range(h, n):
        if s[i] != '0':
            ans = min(ans, int(s[:i]) + int(s[i:]))
            break
    for i in range(h, 0, -1):
        if s[i] != '0':
            ans = min(ans, int(s[:i]) + int(s[i:]))
            break
print(ans)