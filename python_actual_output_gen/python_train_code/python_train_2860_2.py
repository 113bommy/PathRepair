n=int(input())
a=sorted(list(map(int,input().split())))

b=set(a)

c=[2**i for i in range(32)]

ans=0

a=a+[-1]

for i in range(n-1):
    x=a[i]
    t=0
    for j in c:
        y=j-x
        if y in a:
            if y!=x: t=1
            else:
                if a[i-1]==x or a[i+1]==x: t=1
    if t==0: ans+=1

print(ans)

