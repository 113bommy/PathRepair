n=int(input())
a=list(map(int,input().split()))
if(max(a)<500000):
    print(max(a)-1)
    exit()
if(min(a)>500000):
    print(1000000-min(a))
    exit()
mina=-1
maxa=10000000000000
for i in range(0,len(a)):
    if(a[i]<=500000 and a[i]>mina):
        mina=a[i]
for i in range(len(a)-1,-1,-1):
    if(a[i]>=500000 and a[i]<maxa):
        maxa=a[i]
print(min(mina-1,1000000-maxa),)