import sys
input = sys.stdin.readline

N=int(input())
A=[int(input()) for i in range(N)]
SUM=sum(A)
MAX=(SUM-1)//2

mod=998244353

DPLIST=[0]*(MAX+2)
DPLIST[0]=1

for a in A:
    for i in range(MAX+1,-1,-1):
        if i==MAX+1:
            DPLIST[i]=DPLIST[i]*3%mod
        else:
            DPLIST[min(i+a,MAX+1)]=(DPLIST[min(i+a,MAX+1)]+DPLIST[i])%mod
            DPLIST[i]=DPLIST[i]*2%mod

if SUM%2==1:
    print((sum(DPLIST)-DPLIST[-1]*3)%mod)
    sys.exit()

MAX=SUM//2
       
DPLIST2=[0]*(MAX+2)
DPLIST2[0]=1

for a in A:
    for i in range(MAX+1,-1,-1):
        DPLIST2[min(i+a,MAX+1)]=(DPLIST2[min(i+a,MAX+1)]+DPLIST2[i])%mod

        
print((sum(DPLIST)-DPLIST[-1]*3+DPLIST2[-2]*3)%mod)
