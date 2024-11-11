l1,r1=input().split()
l=int(l1)
r=int(r1)
if l%2==0 and r-l>=2:
 print(l,l+1,l+2)
elif l%2==1 and r-1>=3:
 print(l+1,l+2,l+3)
else:
 print(-1)