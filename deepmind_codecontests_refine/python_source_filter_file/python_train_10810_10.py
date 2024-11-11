s = input()
ans = 0
for i in range(1, len(s) // 2 - 1):
  if s[:i] == s[i:2*i]:
    ans = i
print(ans)
