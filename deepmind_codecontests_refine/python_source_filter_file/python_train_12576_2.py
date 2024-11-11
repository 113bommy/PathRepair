N = int(input())
S = [input() for _ in range(N)]
a, b, ab = 0, 0, 0
ans = 0
for s in S:
    ans += s.count('AB')
    if s[-1] == 'A' or s[0] == 'B':
        ab += 1
    if s[-1] == 'A':
        a += 1
    if s[0] == 'B':
        b += 1
print(ans + min(a, b, ab-1))
