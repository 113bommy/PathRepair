n = int(input())
s = input()
ans = 0
for i in range(1, n):
  ans = max(ans, len(set(s[0:i]) & set(s[i:])))
print(ans)