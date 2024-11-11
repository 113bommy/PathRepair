n,m=map(int,input().split())
a=[int(i) for i in input().split()]
x=0
t=0
for i in a:
    if x==0:
        t+=i-1
    else:
        if i>=a[x-1]:
            t+=i-a[x-1]
        else:
            t+=4-a[x-1]+i
    x+=1
print(t)