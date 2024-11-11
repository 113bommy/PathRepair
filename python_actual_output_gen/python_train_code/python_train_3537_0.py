s=input()
if len(s)<26:
  for i in range(97,123):
    if not chr(i) in s:
      print(s+chr(i))
      exit()
else:
  for i in range(24)[::-1]:
    for j in range(i+1,25)[::-1]:
      if s[i]<s[j]:
        print(s[:i]+s[j])
        exit()
  else:
    print(-1)