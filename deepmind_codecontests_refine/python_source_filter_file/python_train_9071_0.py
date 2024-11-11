l,r=map(int,input().split())
m=bin(l-1)
n=bin(r)
no1=list(m)
no2=list(n)
no1=no1[2:]
no2=no2[2:]
q=len(no2)-1
ev=0
odd=0
flag=0
for i in range(0,q):
    if(i%2==0):
        flag=0
        odd+=pow(2,i)
    else:
        flag=1
        ev+=pow(2,i)
s1=pow(2,q)-1
res1=r-s1
if flag==0:
    ev+=res1
else:
    odd+=res1
evensum=(ev+1)*ev
oddsum=odd*odd
result1=oddsum+evensum

q=len(no1)-1
ev=0
odd=0
flag=0
for i in range(0,q):
    if(i%2==0):
        flag=0
        odd+=pow(2,i)
    else:
        flag=1
        ev+=pow(2,i)
s1=pow(2,q)-1
res1=l-1-s1
if flag==0:
    ev+=res1
else:
    odd+=res1
evensum=(ev+1)*ev
oddsum=odd*odd
result2=oddsum+evensum
result=(result1-result2)%1000000007
print(result)

