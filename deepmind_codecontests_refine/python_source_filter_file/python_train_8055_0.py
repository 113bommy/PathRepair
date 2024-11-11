n,m,k=map(int,input().split())

Alice=list(map(int,input().split()))
Bob=list(map(int,input().split()))

SA={}
SB={}

for item in Alice:
    if(item in SA):
        SA[item]+=1
        continue
    SA[item]=1
    SB[item]=0

for item in Bob:
    if(item in SB):
        SB[item]+=1
        continue
    SB[item]=0
    SA[item]=1

x=sorted(list(set(Alice+Bob)),reverse=True)
n=len(x)

done=False
i=0
needed=0
while(i<n):
    if(SA[x[i]]-SB[x[i]]>needed):
        print("YES")
        done=True
        break
    needed+=SB[x[i]]-SA[x[i]]
    i+=1
if(not done):
    print("NO")
