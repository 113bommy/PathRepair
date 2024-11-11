from collections import Counter
n = int(input())
s = input()
c = Counter(s)
ans = 0
for x in c:
    if c[x] > 1:
        ans += c[x] - 1
print(0 if n > 26 else ans)
