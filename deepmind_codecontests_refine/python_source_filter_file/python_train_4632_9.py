s=input()
n,k,p,x,y=s.split()
n,k,p,x,y=int(n),int(k),int(p),int(x),int(y)
s=input()
a=[]
for i in s.split():
    a.append(int(i))
sum=0
l=0
r=0
for i in a:
    sum=sum+i
    if i>=y: r+=1
    else: l+=1
flag=1
b=[]
if sum>=x or l>n//2 or y>p:
    flag=0
else:
    left=x-1-sum
    for i in range(0,n-k):
        if r<n//2+1:
            b.append(y)
            r+=1
        else: b.append(1)
        left-=b[i]
    if left<0 or r<n//2+1:
        flag=0

if flag==1:
    for i in range(0,n-k-1):
        print(b[i],end=' ')
    print(b[n-k-1])
else :
    print(-1)
        
