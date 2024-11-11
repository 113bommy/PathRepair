s=input()
n=len(s)
 
c=0
i=0
while i<n-i-1:
  if s[i]!=s[n-i-1]:
    c+=1
  i+=1
print(c)