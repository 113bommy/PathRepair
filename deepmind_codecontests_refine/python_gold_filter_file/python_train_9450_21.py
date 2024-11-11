n,k=map(int,input().split())
a=list(map(int,input().split()))
c=0
d={}
d[1]=0
dd={}
dd[0]=1
now=1
while True:
    now=a[now-1]
    c+=1
    if now in d:
        break
    d[now]=c
    dd[c]=now
s=d[now]
if k<=s:
    print(dd[k])
    exit()
p=c-s
k-=s
k%=p
k+=s
print(dd[k])
