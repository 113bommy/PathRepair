s = input()
n = len(s)
t = s[::-1]
ans = n
for i in range(n-1):
  if s[i] != s[i+1]:
    ans = min(ans,max(i+1,n-i-1))
print(ans)
