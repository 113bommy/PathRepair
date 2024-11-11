n,k,c=map(int,input().split())
s=input()
ne=10**6*(-1)
fow=[]
bac=[]
for i in range(n):
    if i>ne and s[i]!="x":
        ne=i+c
        fow.append(i)
    if len(fow)==k:
        break
ne=10**6
for i in range(n-1,-1,-1):
    if i<ne and s[i]!="x":
        ne=i-c
        bac.append(i)
    if len(bac)==k:
        break
bac.sort()
for i,j in zip(fow,bac):
    if i==j:
        print(i)