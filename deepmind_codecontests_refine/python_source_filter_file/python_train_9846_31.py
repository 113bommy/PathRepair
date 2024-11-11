n=int(input())
a=list(map(int,input().split()))
if(len(a)==0 or len(a)==1):
    print(0)
else:
    sorted(a)
    x=0
    for i in range(n-1):
        x+=abs(a[n-1]-a[i])
    print(x)