a=""
s,t=input(),input()
for i in range(len(s)):
  a+=s[i]
  if i<len(t)-1:a+=t[i]
print(a)