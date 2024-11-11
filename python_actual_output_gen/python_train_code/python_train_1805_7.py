I=lambda:map(int,input().split())
c=1;mxx=0
n=int(input())
a=list(I())
for i in range(n-1):
    if  a[i+1]<=(2*a[i]):
        c+=1
    else:c=1
    mxx=max(c,mxx)
print(mxx)    