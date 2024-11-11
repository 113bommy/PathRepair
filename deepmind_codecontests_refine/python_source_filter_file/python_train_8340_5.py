n=int(input())
l=list(map(int,input().split()))
b=0
a=[0]*n
a[n-1]=l[0]
for j in range(1,len(l)):
    x=l[j]
    if(x>l[j-1]):
        a[j]=x-a[n-j]
        a[n-j-1]=x-a[j]
    else:
        a[j]=a[j-1]
        a[n-j-1]=x-a[j]
print(a)

