n=input()
n1=0
li=['A','B','C']
for i in range(int(len(n)-2)):
 if n[i] in li:
  if n[i+1] in li and n[i+1]!=n[i]:
   if n[i+2] in li and n[i+2]!=n[i+1] and n[i+2]!=n[i]:
    n1=1
if n1==1:
 print("YES")
else:
 print("NO")