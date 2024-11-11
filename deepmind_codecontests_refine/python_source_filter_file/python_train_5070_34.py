n,B=map(int,input().split())
a=input().split()
for i in range(n):
    a[i]=int(a[i])
b=[]
c1=0
c2=0
if(a[0]%2==0):c1+=1
else:c2+=1
for i in range(1,n):
    if(c1==c2):
        b.append(a[i]-a[i-1])
    if(a[i]%2==0):
        c1+=1
    else:
        c2+=1
b.sort()
count=0
for i in range(len(b)):
    if(B>=b[i]):
        count+=1
        B-=b[i]
print(count)        