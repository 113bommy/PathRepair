n,m=map(int,input().split())
maxi=n-m+1
if maxi>=2:
    ansm=(maxi*(maxi-1))//2
else:
    ansm=maxi
mini=n//m
r=n%m
if r!=0:
    if mini>=1:
        ansi=((mini+1)*(mini))//2
        ansi=ansi*r
        if mini>=2:
            e=(mini*(mini-1)//2)*(m-r)
            ansi=ansi+e
else:
    if mini>=2:
        ansi=((mini*(mini-1))//2)*m
    else:
        ansi=0
print(ansi,ansm)
    