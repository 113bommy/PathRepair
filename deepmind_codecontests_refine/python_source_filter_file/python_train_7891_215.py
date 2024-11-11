m=999
s=input()
for i in range(2,len(s)):
  m=min(m,753-int(s[i-2:i]))
print(m)