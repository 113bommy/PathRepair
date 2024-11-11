import sys
import copy
input = sys.stdin.readline

n,q=map(int,input().split())
Q=[list(map(int,input().split())) for i in range(q)]
Q.sort()

LIST=[0]*(n+2)
for l ,r in Q:
    LIST[l]+=1
    LIST[r+1]-=1

SUM=[0]
for i in range(1,n+2):
    SUM.append(LIST[i]+SUM[-1])

ONES=[0]
TWOS=[0]

for i in range(1,n+2):
    if SUM[i]==1:
        ONES.append(ONES[-1]+1)
    else:
        ONES.append(ONES[-1])

    if SUM[i]==2:
        TWOS.append(TWOS[-1]+1)
    else:
        TWOS.append(TWOS[-1])

ANS=sum([1 for a in SUM if a>=1])
MINUS=10**10
for i in range(q-1):
    for j in range(i+1,q):
        l0,r0=Q[i][0],Q[i][1]
        l1,r1=Q[j][0],Q[j][1]

        if l1>r0:
            MICAN=(ONES[r0]-ONES[l0-1])+(ONES[r1]-ONES[l1-1])

        elif l1<=r0 and r1>r0:
            MICAN=(ONES[l1]-ONES[l0-1])+(TWOS[r0]-TWOS[l1-1])+(ONES[r1]-ONES[r0-1])

        elif l1<=r0 and r1<=r0:
            MICAN=(ONES[l1]-ONES[l0-1])+(TWOS[r1]-TWOS[l1-1])+(ONES[r1]-ONES[r1-1])

        if MICAN<MINUS:
            MINUS=MICAN
            
        #print(i,j)
        #print(l0,r0,l1,r1)
        #print(MICAN)

print(ANS-MINUS)
                                                    
                                                                                 
        




