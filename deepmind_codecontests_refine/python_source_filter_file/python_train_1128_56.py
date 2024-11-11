N=int(input())
a=list(map(int,input().split()))
b=[0]*8

f=0
for i in a:
  if i//400<=7:
    b[i//400]=1
  else:
    f+=1    
    
sb=sum(b)
print(max(sb,1),min(sb+f,8))