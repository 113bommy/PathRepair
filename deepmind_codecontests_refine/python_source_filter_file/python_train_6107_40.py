a=input()
m=b=0
for i in range(len(a)-1):
 if a[i]==a[i+1]:
  b+=1
  if b>m:
   m=b
 else:b=0
if m>=7:print('YES')
else:print('NO')