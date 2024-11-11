r1=r2=u1=u2=1<<30
l1=l2=d1=d2=-r1
for i in range(int(input())):
 l,d,r,u=map(int,input().split())
 if l>l1:il,l1,l2=i,l,l1
 elif l>l2:l2=l
 if r<r1:ir,r1,r2=i,r,r1
 elif r<r2:r2=r
 if d>d1:idn,d1,d2=i,d,d1
 elif d>d2:d2=d
 if u<u1:iu,u1,u2=i,u,u1
 elif u<u2:u2=u
for i in il,ir,idn,iu:
 l=(l1,l2)[i!=il];r=(r1,r2)[i!=ir];d=(d1,d2)[i!=idn];u=(u1,u2)[i!=iu]
 if l<=r and d<=u:break
print(l,r)