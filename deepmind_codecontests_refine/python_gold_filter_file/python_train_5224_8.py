l=int(input())
n=input()
nn=list()
for i in range(l):
    nn.append(n[i])
k=list()
p=-1
for i in range(10):
    k.append(0)
for i in range(l):
    if nn[i]!='L' and nn[i]!='R':
        p=int(nn[i])
        k[p]=0
        
    if nn[i]=='L':
        for j in range(10):
            if k[j]==0:
                k[j]=1
                break
    if nn[i]=='R':
        for j in range(9,-1,-1):
            if k[j]==0:
                k[j]=1
                break
for i in k:
    print(i,end="")
