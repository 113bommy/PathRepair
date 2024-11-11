n=int(input())
ar=list(map(int,input().split()))
d={};ans=0
for i in ar:d[i]=d.get(i,0)+1
for i in ar:
  flag=False
  for j in range(31):
    k=2**j;
    if k>=i:
     k1=k-i
     if i!=k1 and d.get(k1,0)>0:flag=True;break
     if i==k1 and d.get(i,0)>1:flag=True;break
  if not flag:ans+=1
    
print(ans)
