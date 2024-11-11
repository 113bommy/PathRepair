import bisect
n,m=map(int,input().split())
a=list(map(int,input().split()))
p=[a[0]]
for i in range(1,n):
    p.append(p[i-1]+a[i])
print(p)
b=list(map(int,input().split()))
for x in b:
    i=bisect.bisect_left(p,x)
    print(i+1,end=" ")
    if(i==0):
        print(x)
    else:
        print(x-p[i-1])
