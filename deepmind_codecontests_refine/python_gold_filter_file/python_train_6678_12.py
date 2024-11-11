n=int(input('')) 
a=list(map(int, input().split()))
b=[]
c=[]
for i in range(200005):
  c.append(0)
mc=-1
m=-1  
for i in range(len(a)):
  c[a[i]]+=1
  if c[a[i]]>=mc:
    mc=c[a[i]]
    m=a[i]
ans=1
u=0
l=n-1

if mc==n:
  ans=0
  print(ans)
for i in range(n):
  if a[i]==m:
    u=i
    break
ud=u
ld=n-u-1      
if ans==1:
  for i in range (u+1,n):
    if a[i]==a[i-1] :
      continue
    elif a[i]>a[i-1]:
      b.append([2,i+1,i])
      a[i]=a[i-1]
    else:
      b.append([1,i+1,i])
      a[i]=a[i-1]
  
  for i in range (u-1,-1,-1):
    if a[i]==a[i+1] :
      continue
    elif a[i]>a[i+1]:
      b.append([2,i+1,i+2])
      a[i]=a[i+1]
    else:
      b.append([1,i+1,i+2])
      a[i]=a[i+1]        
  
  print(len(b))
  for i in range(len(b)):
    for j in range(3):
      print(b[i][j],end=" ")
    print()

 