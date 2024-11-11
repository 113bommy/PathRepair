from collections import defaultdict as dd
n,m=[int(i) for i in input().split(' ')]
a=[]
b=[]

def fnx(i,j):
    if i<j:
        return(j-i)
    else:
        return(n-i+j)

def fnr(r):
    if r%n==0:
        return(n)
    else:
        return(r%n)

for i in range(m):
    x,y=[int(i) for i in input().split(' ')]
    a.append(x)
    b.append(y)
    
ANS=[]

ii=1
s=[[] for i in range(n+1)]
d=dd(list)

r=[ -1 for i in range(n+1)]
y=[-1]

for i in range(m):
    x,yy=a[i],b[i]
    s[x].append([fnx(x,yy),x,yy])    
    d[yy].append(x)
    
for i in range(1,n+1):
    rt=s[i].copy()
    rt.sort()
    r[i]=rt
    y.append(len(s[i]))
#print(r)


p=max(y)
A=(p-2)*n
ans1=[]
ans2=[]
for i in range(1,n+1):
    if y[i]==p:
        if p==1:
            ans2.append(r[i][0])
            continue
        ans1.append(r[i][1])
        ans2.append(r[i][0])
    if y[i]==p-1:
        if p-1==0:
            continue
        ans1.append(r[i][0])

tr=0

for ij in range(1,n+1):
    
    for i in range(len(ans1)):
        re=ans1[i][0]+fnr(ans1[i][1]-ij+1)-1
        tr=max(tr,re)
        
    trf=0
    for i in range(len(ans2)):
        re=ans2[i][0]+fnr(ans2[i][1]-ij+1)-1
        trf=max(trf,re)

    er=max(A+tr,A+trf+n)
    #print(er)
    ANS.append(er)
print(*ANS)
