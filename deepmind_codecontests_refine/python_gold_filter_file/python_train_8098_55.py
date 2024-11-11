x=int(input())

ans=0
for i in range(1,x+1):
  if len(str(i))%2==1:
    ans+=1
    
print(ans)