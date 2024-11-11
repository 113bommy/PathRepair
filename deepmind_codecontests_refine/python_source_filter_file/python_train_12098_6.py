T=int(input())
for _ in range(T):
 n=int(input());ans=[]
 if n==1:print(2);print(0,1);continue
 elif n==2:print(2);print(0,1,2);continue
 elif n==3:print(3);print(0,1,3);continue
 k=n//2;a=2
 l=1;r=n//2;ans=[0,1]
 while True:
  ans.append(a)
  if r==1:break
  #print(ans)
  while l<=r:
   mid=(l+r)//2
   if n//mid>a:a1=n//mid;a2=mid;l=mid+1
   else:r=mid-1
  #print(a1,a2)
  a=a1;r=a2;l=1
 print(len(ans))
 print(*ans)
