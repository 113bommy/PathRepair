n,m=[int(i) for i in input().split()]
x=[]
for i in range(n):
    a=input()
    x.append(a)
print(x)
r=False
c=False
rsn=None
ren=None
csn=None
cen=None
for i in range(n):
    for j in range(m):

        if r==False and x[i][j]=='*':
            r=True
            rsn=i
            ren=i
            csn=j
            cen=j
        if r==True and x[i][j]=='*':
            rsn=min(rsn,i)
            ren=max(ren,i)
            csn=min(csn,j)
            cen=max(cen,j)
while rsn<=ren:
    i=csn
    while i<=cen:
        print(x[rsn][i],end="")
        i+=1
    print("")
    rsn+=1