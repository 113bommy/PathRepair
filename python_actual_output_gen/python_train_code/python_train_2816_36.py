n = int(input())
s = input()

ans = 0
for i in range(1, n-1):
  ans = max(ans, len(set(s[:i+1]) & set(s[i:])))
print(ans)