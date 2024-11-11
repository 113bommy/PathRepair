n=int(input())
L=[int(i) for i in input().split()]
moins=[]
plus=[]

for i in range(len(L)):
    if L[i]<0:
        moins.append(-1-L[i])
        plus.append(1-L[i])
    elif L[i]==0:
        moins.append(1)
        plus.append(1)
    else:
        plus.append(-1+L[i])
        moins.append(1+L[i])
c=0
s=0
p=1
B=list(L)
for i in range(len(L)):
    c+=min(moins[i],plus[i])
    s=min(moins[i],plus[i])
    if L[i]<=0:
        B[i]+=s
        p*=B[i]
    else:
        B[i]-=s
        p*=B[i]
if p==1:
    print(c)
else:
    c=c-min(moins[0],plus[0])+max(moins[0],plus[0])
    for i in range(1,len(L)):
        l=c-min(moins[i],plus[i])+max(moins[i],plus[i])
        if c>l:
            c=l
    print(c)