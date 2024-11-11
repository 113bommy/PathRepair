n = int(input())
s = input()
ans = 0
for i in range(1,len(s)-1):
  ans = max(ans, len(set(s[:i]) & set(s[i+1:])))
print(ans)