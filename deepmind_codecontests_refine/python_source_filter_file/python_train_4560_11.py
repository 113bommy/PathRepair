#OK牧場
n,k=map(int,input().split())
a=sorted(list(map(int,input().split())))
#こっちは変えられない
f=sorted(list(map(int,input().split())),reverse=True)
l,r=0,10**12
def cal(x):
    global n,f,a,k
    ret=0
    for i in range(n):
        ret+=max(0,a[i]-(x//f[i]))
    #print(ret,x)
    return ret
while l+1<r:
    x=l+(r-l)//2
    if cal(x)<=k:
        r=x
    else:
        l=x
if cal(l)<=k:
    print(l)
else:
    print(r)