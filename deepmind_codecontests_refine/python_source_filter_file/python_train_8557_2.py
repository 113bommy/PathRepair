n,k=map(int,input().split())
def calc(z):
    global n
    if z>n:
        return True
    if z==0:
        return True
    if z%2==1:
        ans=1
        now=2*z
        co=1
        if k==1:
            return True
        elif now>n:
            return False
    else:
        ans=0
        now=z
        co=1
    #print(ans,now,co)
    while True:
        #print(n,now+2*co-1,now)
        #print(n-(now)+1)
        if n<=now+2*co-1:
            ans+=max(0,n-(now)+1)
            #print(ans)
            break
        else:
            now*=2
            co*=2
            ans+=(co)
            #print(ans)
    #print(ans)
    return ans>=k
realans=[]
#odd(2x-1)
l=1
r=n//2+1
while l+1<r:
    y=l+(r-l)//2
    if calc(2*y-1):
        l=y
    else:
        r=y
realans.append(2*l-1)
#even(2x)
l=0
r=n//2+1
while l+1<r:
    y=l+(r-l)//2
    if calc(2*y):
        l=y
    else:
        r=y
realans.append(2*l)
print(max(realans))