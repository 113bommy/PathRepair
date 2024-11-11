a=list(map(int,input().split()))
m=0
s=sorted(a)
if(a[0]+a[1]>a[2]):
    print(m)
else:
    print(a[2]+1-a[0]-a[1])