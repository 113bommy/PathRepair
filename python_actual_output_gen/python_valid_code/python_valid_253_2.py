a=int(input())
b=[]
cnt=0
d=0
for i in range(a):
  b.append(input())
for i in range(a):
  if 'OO' in b[i]:
    b[i]=b[i].replace('OO','++')
    cnt=1
    break
    
if cnt==1:
  print("YES")
  for i in range(a):
    print(b[i])
else:
  print("NO")
  
      
     
    