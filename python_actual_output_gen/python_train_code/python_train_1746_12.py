nmin=999999999
nmax=-1
mmin=999999999
mmax=-1
for _ in range(int(input())):
    a,b=[int(x) for x in input().split()]
    if a>nmax:
        nmax=a
    if b<nmin:
        nmin=b
for _ in range(int(input())):
    a,b=[int(x) for x in input().split()]
    if a>mmax:
        mmax=a
    if b<mmin:
        mmin=b
ans=max(mmax-nmin,nmax-mmin)
if ans<=0:
    print(0)
else:
    print(ans)