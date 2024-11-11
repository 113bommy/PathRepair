s = input()
t = input()
ans = len(t)
for i in range(len(s)-len(t)):
  tmp = 0
  for j in range(len(t)):
    if s[i+j] != t[j]:
      tmp += 1
  ans = min(ans, tmp)
print(ans)