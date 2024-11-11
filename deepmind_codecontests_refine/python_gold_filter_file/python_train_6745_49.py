s=input()
n=len(s)//2
c=0
for i in range(n):
  if s[i]!=s[-i-1]:
    c+=1
print(c)

