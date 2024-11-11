s = input()

n = len(s)
ans = n
for i, (c1, c2) in enumerate(zip(s[:-1], s[1:])):
    if c1 == c2:
        continue
    ans = min(ans, max(i + 1, n - i - 1))

print(ans)
