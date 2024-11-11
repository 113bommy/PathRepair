N,K,C=map(int,input().split())
SL=input()
SR=SL[::-1]
Left=[]
Right=[]
Last=-N-1
Rast=-N-1
cL=cR=0
for i in range(N):
    if SL[i]=="o" and i-Last>C and cL<=K:
        Left.append(i)
        Last=i
        cL+=1
    if SR[i]=="o" and i-Rast>C and cR<=K:
        Right.append(N-i-1)
        Rast=i
        cR+=1
Right=Right[::-1]

ans=[]
for k in range(K):
    if Left[k]==Right[k]:
        ans.append(Left[k]+1)

if len(ans)==0:
    print()
else:
    for a in ans:
        print(a)