n=int(input())
c=0
k=0
count=0
count1=0
fin=""
for i in range(n):
 t,a,b=map(int,input().split())
 if t==1:
  c+=a
  count+=1
 else:
  k+=a
  count1 +=1
fin="LIVE" if c>=(count*10)//2 else "DEAD"
print(fin)
fin="lIVE" if k>=(count1*10)//2 else "DEAD"
print(fin)