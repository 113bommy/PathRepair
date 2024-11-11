nlr=list(map(int,input().split()))
n=nlr[0]
l=nlr[1]
r=nlr[2]
li=[0]*2
if l==1:
    li[0]=n*1
else:
    for i in range(0,l):
        li[0]=li[0]+pow(2,i)
    li[0]=li[0]+(n-l)
for i in range(0,r):
    li[1]=li[1]+pow(2,i)
if r<n:
    li[1]=li[1]+(n-r)*pow(2,i)
print(li[0],end=" ")
print(li[1])