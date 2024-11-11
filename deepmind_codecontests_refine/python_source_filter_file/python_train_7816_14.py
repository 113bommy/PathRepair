n = int(input())
s = input()
d = {}
for i in range(n):
    if s[i] not in d:
        d[s[i]] = 1
    else:
        d[s[i]] += 1
if max(d.values()) >= 2 or n == 2:
    print("YES")
else:
    print("NO")
