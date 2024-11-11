n,k=map(int,input().split())
l=[int(i) for i in input().split()]
psum=[0]*n 
psum[0]=l[0] 
for i in range(1,n):
    psum[i]=psum[i-1]+l[i]
mini=1000000000
curr=0 
for i in l:
    curr=min(curr+i,i)
    mini=min(mini,curr)
pos_max=0 
curr=0 
for i in l:
    curr=max(curr+i,i)
    pos_max=max(pos_max,curr)
m=pos_max
m1=max(l)
m2=-mini
m=max(m,m1,m2)
f=1 
if -min(psum)>k or max(psum)>k:
    f=0 
if not f:
    print(0)
else:
    print(max(k-m+1,0))