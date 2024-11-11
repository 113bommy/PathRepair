import sys
import copy

input = sys.stdin.readline

n,m=map(int,input().split())
MAT=[list(map(int,input().split())) for i in range(n)]

#n=3
#m=3
#MAT=[list(range(j*j,j*j*(m+1),j*j)) for j in range(1,n+1)]


if n==1:
    ANS=10**10
    for i in range(1,m):
        if ANS>abs(MAT[0][i]-MAT[0][i-1]):
            ANS=abs(MAT[0][i]-MAT[0][i-1])
    print(ANS)
    sys.exit()



EDGE0=[[10**10]*n for i in range(n)]#iが0行目,jが最終行
EDGE1=[[10**10]*n for i in range(n)]
MAX=0
MIN=0

if m!=1:    
    for i in range(n):
        for j in range(n):

            EDGE1[i][j]=EDGE1[j][i]=min([abs(MAT[i][k]-MAT[j][k]) for k in range(m)])
            
            if EDGE1[i][j]>MAX:
                MAX=EDGE1[i][j]

            EDGE0[i][j]=min([abs(MAT[i][k]-MAT[j][k-1]) for k in range(1,m)])
else:
    for i in range(n):
        for j in range(n):

            EDGE1[i][j]=EDGE1[j][i]=min([abs(MAT[i][k]-MAT[j][k]) for k in range(m)])
            
            if EDGE1[i][j]>MAX:
                MAX=EDGE1[i][j]
    

def Hamilton(start,USED,rest,last,weight):
    #print(start,USED,rest,last,weight,last*(1<<n)+USED)
    if MEMO[last*(1<<n)+USED]!=2:
        return MEMO[last*(1<<n)+USED]
    if rest==1:
        for i in range(n):
            if USED & (1<<i)==0:
                final=i
                break

        if EDGE0[start][final]>=weight and EDGE1[last][final]>=weight:
            #print(start,USED,rest,last,weight)

            MEMO[last*(1<<n)+USED]=1
            return 1
        else:
            #print(start,USED,weight,"!")
            MEMO[last*(1<<n)+USED]=0
            return 0

    for j in range(n):
        if USED & (1<<n)==0 and EDGE1[last][j]>=weight:
            

            NEXT=USED+(1<<j)
            if Hamilton(start,NEXT,rest-1,j,weight)==1:
                #print(start,USED,rest,last,weight)
                MEMO[last*(1<<n)+USED]=1
                return 1
    else:
        #print(start,USED,weight,"?")
        MEMO[last*(1<<n)+USED]=0
        return 0
        
    
while MAX!=MIN:
    #print(MAX,MIN)
    aveweight=(MAX+MIN+1)//2

    for start in range(n):
        MEMO=[2]*(n*1<<(n+1))
        START=1<<start
        if Hamilton(start,START,n-1,start,aveweight)==1:
            MIN=aveweight
            break
    else:
        MAX=aveweight-1

print(MAX)
