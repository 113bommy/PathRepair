n,c=map(int,input().split())

l=list(map(int,input().split()))
f=0
if(n>1):
    for i in range(1,n):
        d = l[i]-l[i-1]
        if(d>c):
            f=1
        else:
            f=f+1
else:
    f=1
print(f)