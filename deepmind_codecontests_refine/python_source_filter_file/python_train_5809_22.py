N,M=map(int,input().split())
A=list(map(int,input().split()))

A.sort()

OK=0
NG=max(A)*2+1

import bisect

while NG-OK>2: #N*N個の中で,mid以上の個数がM個以上あればOK
    mid=(OK+NG)//2

    score=0

    for a in A:
        x=bisect.bisect_left(A,mid-a)
        score+=N-x
        if score>=M:
            OK=mid
            break
    else:
        NG=mid
        
from itertools import accumulate
S=list(accumulate(A))

ANS=0
ups=0
for a in A:
    x=bisect.bisect_right(A,OK-a)
    if x!=0:
        ANS+=(N-x)*a+(S[-1]-S[x-1])
    else:
        ANS+=(N-x)*a+S[-1]
        
    #print(x,ANS)
    ups+=N-x
#print(ANS)
ANS+=(M-ups)*OK
print(ANS)
    
    
