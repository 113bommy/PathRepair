s = input()
for k in range(len(s)//2-1, 0, -1)
  if s[:k] == s[k:2*k]: break
print(k)