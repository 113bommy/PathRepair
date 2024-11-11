n=int(input())
a1=list(map(int,input().split()))
a=list(map(int,input().split()))
a=[0]+a
d=[0]*(n+1);
mx=0
for i in range(1,n+1):
    d[a[i]]=i
mx=max(d[i]-i+1 for i in range(1,n+1))
br=n-d[1]+1
b=True
for i in range(1,n+1):
    if(i<=br):
        if(d[i]-d[1]==i-1):
            continue
        else:
            b=False
            break
    else:
        if(d[i]<i-br):
            continue
        else:
            b=False
            break
if(b):
    print(n-br)
else:
    print(n+mx)
