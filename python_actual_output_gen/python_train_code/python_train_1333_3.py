x,y=map(int,input().split())
s=sorted(list(map(int,input().split())))

def ck(x,y,s):
    res=0
    ln=len(s)
    for n in range(ln//2,ln):
        res+=max(0,x-s[n])

    return res<=y

res=0
hi=10**9
lo=0

while hi>=lo:
    mid=(hi+lo)//2
    if ck(mid,y,s):
        res=mid
        lo=mid+1
    else:
        hi=mid-1

print(res)
