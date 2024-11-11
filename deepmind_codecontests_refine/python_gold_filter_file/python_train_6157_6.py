firstline=input().split()
x1=int(firstline[0])
y1=int(firstline[1])
secondline=input().split()
x2=int(secondline[0])
y2=int(secondline[1])
n=int(input())
i=1
m=input()
up=[]
right=[]
up.append(0)
right.append(0)
for j in m:
   up.append(up[i-1])
   right.append(right[i-1])
   if j=='U':
       up[i]+=1
   elif j=='D':
       up[i]-=1
   elif j=='L':
       right[i]-=1
   elif j=='R':
       right[i]+=1
   i+=1
l=0
r=int(1e14+5)
f=True
while l<r:
    mid=int((l+r)>>1)
    len=int(mid/n)
    less=mid%n
    x=x1+len*right[n]+right[less]
    y=y1+len*up[n]+up[less]
    sum=abs(x-x2)
    sum+=abs(y-y2)
    if sum<=mid:
        f=False
        r=mid
    else:
        l=mid+1
if r==int(1e14+5):
    print(-1)
else:
    print(r)
