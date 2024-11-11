n, k = map(int, input().split())
s = input()
l = [0]
for i in range(n - 1):
    if s[i] != s[i + 1]:
        l.append(i + 1)
l += [n]
le = len(l)
ans = 0
for i in range(le - 1):
    if s[l[i]] == "0":
        ans = max(ans, l[min(le, k * 2 + i)] - l[i])
    else:
        ans = max(ans, l[min(le, k * 2 + i + 1)] - l[i])
print(ans)