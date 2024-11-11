n=int(input())
if((n-1)%2==1):
  c=((n-1)//2)+1
else:
  c=(n-1)//2	
c+=1
r=1
print(c)	
for i in range(1,c+2):
  if(i<=n-c):
    print("1",end=" ")
    print(i)
  else:
    print(c,end=" ")
    print(r)
    r+=1
    
