n=int(input())
a=[0]+list(map(int,input().split()))
o=[0]*(n+1)
e=[0]*(n+1)
for i in range(1,n+1):
    if i&1:
        o[i]=o[i-1]+a[i]
        e[i]=e[i-1]
    else:
        o[i]=o[i-1]
        e[i]=e[i-1]+a[i]
x,y=0,0
cnt=0
for i in range(1,n+1):
    if i&1:
        y=o[i-1]+e[n]-e[i]
        x=e[i]=o[n]-o[i]
    else:
        x=e[i-1]+o[n]-o[i]
        y=o[i]=e[n]-e[i]
    if x==y:
        cnt+=1
print(cnt)