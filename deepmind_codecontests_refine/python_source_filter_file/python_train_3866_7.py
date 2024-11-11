import sys

n=int(input())
S=input()

L=[0]
for s in S:
    if s=="(":
        L.append(L[-1]+1)
    else:
        L.append(L[-1]-1)

if L[-1]==2:
    if min(L)<0:
        print(0)
        sys.exit()
    ANS=0

    for j in range(n,-1,-1):
        if L[j]<2:
            #print(j)
            break

    for k in range(j,n):
        if S[k]=="(":
            ANS+=1

    print(ANS)

elif L[-1]==-2:
    if min(L)<-2:
        print(0)
        sys.exit()
    ANS=0

    for j in range(1,n+2):
        if L[j]<2:
            #print(j)
            break

    for k in range(j-1,-1,-1):
        if S[k]==")":
            ANS+=1

    print(ANS)

else:
    print(0)
