s=input()
c=0
k=0
for i in s:
  if(i=='B'):
    c+=1
  else:
    k+=c
print(k)