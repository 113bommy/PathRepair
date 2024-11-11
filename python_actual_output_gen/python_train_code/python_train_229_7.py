def gns():
    return  list(map(int,input().split()))
n,m,k=gns()
ms=gns()
ms=[x-1 for x in ms]
ans=0
if k==1:
    print(m)
    quit()

i=0
while i<m:
    ans+=1
    p=(ms[i]%k+k-i%k)%k
    to=ms[i]+(k-p)
    while i<m and ms[i]<=to:
        i+=1
print(ans)