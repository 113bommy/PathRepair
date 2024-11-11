q=int(input())
w=list(map(int,input().split()))
e=[0]*(q+3)
for i in w:e[i]+=1
r=e.copy()
for i in range(1,q+3):
    if e[i]!=0:
        e[i+2]=0
        e[i+1]=0
for i in range(1,q+3):
    if r[i]>1:
        if r[i-1]==0:
            r[i]-=1
            r[i-1]=1
    if r[i]>1:
        r[i]-=1
        r[i+1]+=1
mn=0
mx=0
for i in range(len(e)):
    if e[i]!=0:mn+=1
    if r[i]!=0:mx+=1
print(mn,mx)