import bisect

n=int(input())
A=list(map(int,input().split()))

B=sorted(A)
l=bisect.bisect_left(B,0)
r=bisect.bisect_right(B,0)

MINUS=B[:l]
PLUS=B[r:]
ZERO=B[l:r]

ZEROLIST=[]
for i in range(n):
    if A[i]==0:
        ZEROLIST.append(i)


USED=[]

if len(ZERO)==n:
    True
    
if len(ZERO)==n-1 and len(MINUS)==1:
    True
    
elif len(MINUS)%2==0 and len(ZERO)!=0:
    for i in range(1,len(ZEROLIST)):
        print(1,ZEROLIST[i-1]+1,ZEROLIST[i]+1)
        USED.append(ZEROLIST[i-1]+1)

    print(2,ZEROLIST[-1]+1)
    USED.append(ZEROLIST[-1]+1)

elif len(MINUS)%2==0 and len(ZERO)==0:
    True
    #DEL=PLUS[0]
    #print(2,A.index(DEL)+1)
    #USED.append(A.index(DEL)+1)

elif len(MINUS)%2==1 and len(ZERO)==0:
    DEL=MINUS[-1]
    print(2,A.index(DEL)+1)
    USED.append(A.index(DEL)+1)

elif len(MINUS)%2==1 and len(ZERO)!=0:
    DEL=MINUS[-1]
    ZEROLIST.append(A.index(DEL))
    for i in range(1,len(ZEROLIST)):
        print(1,ZEROLIST[i-1]+1,ZEROLIST[i]+1)
        USED.append(ZEROLIST[i-1]+1)

    print(2,ZEROLIST[-1]+1)
    USED.append(ZEROLIST[-1]+1)
    True
    #DEL=PLUS[0]
    #print(2,A.index(DEL)+1)
    #USED.append(A.index(DEL)+1)
    



NOKORI=sorted(list(set(range(1,n+1))-set(USED)))

for i in range(1,len(NOKORI)):
    print(1,NOKORI[i-1],NOKORI[i])