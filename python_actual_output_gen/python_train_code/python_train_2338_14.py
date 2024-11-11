s=input();l=len(s)//2-1;c=0
for i in range(l):
  if s[i]!=s[-i]:
    c+=1
print(c)