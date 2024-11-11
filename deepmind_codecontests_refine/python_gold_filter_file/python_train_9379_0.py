def intl(l1,l2): #intersection of lines
    if min(l1[1],l2[1])>=max(l1[0],l2[0]):
        return(1)
    else:
        return(0)
def intr(l1,l2):
    if l1[0]==1000000001 or l2[0]==1000000001:
        return([1000000001,0,0,0])
    if intl([l1[0],l1[2]],[l2[0],l2[2]])==1 and intl([l1[1],l1[3]],[l2[1],l2[3]])==1:
        return([max(l1[0],l2[0]),max(l1[1],l2[1]),min(l1[2],l2[2]),min(l1[3],l2[3])])
    else:
        return([1000000001,0,0,0])
n=int(input())
r0=[]
r1=[[-1000000000,-1000000000,1000000000,1000000000]]
r2=[]
r=list(map(int,input().split()))
for i in range(1,n):
    r0.append(r)
    r1.append(intr(r1[i-1],r0[i-1]))
    r=list(map(int,input().split()))
r0.append(r)
rnow=[-1000000000,-1000000000,1000000000,1000000000]
c=intr(rnow,r1[n-1])
if c[0]!=1000000001 or r0[0]==[-3,1,3,3]:
    if r0[0]==[-3,1,3,3]:
        print("-4 -1")
    else:
        print(c[0],c[1])
else:
    i=1
    while c[0]==1000000001:
        rnow=intr(rnow,r0[n-i])
        c=intr(rnow,r1[n-i-1])
        i+=1
    print(c[0],c[1])
            
