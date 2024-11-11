n,k=map(int,input().strip().split())
a =list(map(int,input().strip().split()))
from collections import deque, Counter
temp = Counter(a)
a = deque(sorted(map(lambda x: [x,temp[x]], temp)))
# print(a)
while( (k>=a[0][1] or k>=a[-1][1] ) and len(a)>1):
    # forward
    cf,f,smf = a[0][1], a[0][0], a[1][0]
    cr,r,smr = a[-1][1], a[-1][0], a[-2][0]

    if(cf < cr):
        # front should be removed
        temp = cf*(smf-f)
        if(temp<=k):
            k-=temp
            a.popleft()
            a[0][1]+=cf
        else:
            factor=k//cf
            temp1 = factor*cf
            k-=temp1
            a[0][0]=f+factor




    else:
        # back should be removed
        temp = cr*(r-smr)
        if(temp<=k):
            k-=temp
            a.pop()
            a[-1][1]+=cr
        else:
            factor=k//cr
            temp1 = factor*cr
            k-=temp1
            a[-1][0]=r-factor


print(max(a)[0]-min(a)[0])