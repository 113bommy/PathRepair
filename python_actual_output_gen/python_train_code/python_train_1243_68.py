n=list(map(int,input().split()))
i=1
c=0
while(i<=n[0]):
  a=input().split()
  if(a[0]=="-" and int(a[1])<n[1]):
    n[1]-=int(a[1])
  elif(a[0]=="-"):
    c+=1
  else:
    n[1]+=int(a[1])
  i+=1  
print(n[1] , c)
