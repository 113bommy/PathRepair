n=int(input())
a=list(map(int,input().split()))
temp=0;s=0;x=0
for i in a:
    if(i==1):
        s+=i
    elif i==0:
        if(s>temp):
            temp=s
        s=0
if(s>temp):
    temp=s
if(temp>0 and temp!=n):
    ind=a.index(0)
    for i in range(ind):
        x+=a[i]
    for i in range(n-1,-1,-1):
        if(a[i]==0):
            break
        else:
            x+=a[i]
if(x>temp):
    print(x)
else:
    print(temp)
