import sys
input = sys.stdin.readline

n,m=map(int,input().split())
D=[0]*(n+1)

for i in range(m):
    x,y,z=map(int,input().split())

    D[x]+=z
    D[y]-=z

PLUS=[]
MINUS=[]

for i in range(n+1):
    if D[i]>0:
        PLUS.append([D[i],i])

    elif D[i]<0:
        MINUS.append([-D[i],i])

Pind=0
Mind=0
PMAX=len(PLUS)
MMAX=len(MINUS)
ANS=[]


while Pind<PMAX and Mind<MMAX:
    if PLUS[Pind][0]>MINUS[Mind][0]:
        PLUS[Pind][0]-=MINUS[Mind][0]
        ANS.append((PLUS[Pind][1],MINUS[Mind][1],MINUS[Mind][0]))
        
        Mind+=1

    elif PLUS[Pind][0]==MINUS[Mind][0]:
        ANS.append((PLUS[Pind][1],MINUS[Mind][1],MINUS[Mind][0]))
        
        Mind+=1
        Pind+=1

    else:
        MINUS[Mind][0]-=PLUS[Pind][0]
        ANS.append((PLUS[Pind][1],MINUS[Mind][1],PLUS[Pind][0]))
        
        Pind+=1

print(len(ANS))
for x,y,z in ANS:
    print(x,y,z)
        


