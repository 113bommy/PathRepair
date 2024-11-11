n,x=map(int,input().split())

A={}

L=list(map(int,input().split()))

minn=min(L)


ind=x-1
    
while(L[ind]!=minn):
    ind-=1
    if(ind==-1):
        ind=n-1
        


iterations=L[ind]

Diff=[0]*n
r=1
inc=True
if(x-1==ind):
    inc=False
i=ind+1
start=True

rem=0
while(i!=ind+1 or start):
    start=False
    if(i==n):
        i=0
    if(i==x-1 and inc):
        rem+=1
        inc=False
        L[i]-=iterations+r
        i+=1
        continue
    if(inc):
        rem+=1
        L[i]-=iterations+r
    else:
        L[i]-=iterations
    i+=1
if(ind!=0):
    if(L[0]<0):
        while(1):
            x=1
    print(L[0],end="")
else:
    print(iterations,end="")
for i in range(1,n):
    if(i==ind):
        print(" "+str(iterations*n+rem),end="")
        continue
    if(L[i]<0):
        while(1):
            x=1
    print(" "+str(L[i]),end="")
print()
