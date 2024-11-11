n=int(input())
m=list(map(int,input().split()))
ma=max(m)
mi=min(m)
mai,mii=0,0
for i in range(0,n):
    if m[i]==ma:
        mai=i+1 
        break
c=n-1
while c>0:
    if m[c]==mi:
        mii=c+1 
        break 
    c-=1
if mai<mii:
    print(abs(mai-1)+abs(mii-n))
else:
    print(abs(mai-1)+abs(mii-n)-1)
    