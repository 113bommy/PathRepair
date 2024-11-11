import sys
input = sys.stdin.readline

n,m,k=map(int,input().split())
A=list(map(int,input().split()))
A.append(n+1)
COMP=[]
NOW=0
for a in A:
    if a-NOW-1!=0:
        if a-NOW-1>2*k:
            COMP.append([(a-NOW-1)%k+k,0])
        else:
            COMP.append([a-NOW-1,0])
    COMP.append([1,1])
    NOW=a
    
COMP.pop()

#print(COMP)

ANS=0
NOW_PAGE=0
NOW_SCORE=0

pa=0
LEN=len(COMP)
while pa<LEN:
    i,j=COMP[pa]
  
    if NOW_PAGE+i<=k:
        NOW_PAGE += i
        NOW_SCORE += j
        pa+=1

    else:
        if NOW_SCORE>0:

            COMP[pa][0]-=k-NOW_PAGE
            NOW_PAGE=k-NOW_SCORE

            ANS+=1
            NOW_SCORE=0

        else:
            if NOW_PAGE==k:
                NOW_PAGE=0
                
            else:              
                COMP[pa][0]-=k-NOW_PAGE
                NOW_PAGE=k-NOW_SCORE

    #print(i,j,pa,NOW_PAGE,NOW_SCORE,ANS,COMP)

if NOW_SCORE>0:
    ANS+=1
    
print(ANS)

        
        
    
