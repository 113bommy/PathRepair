import sys
input=sys.stdin.buffer.readline #FOR READING PURE INTEGER INPUTS (space separation ok)

def getCnts(j,l,r):
    if l>r:
        return 0
    if l==0:
        return prefCnt[r][j]
    else:
        return prefCnt[r][j]-prefCnt[l-1][j]

t=int(input())
for _ in range(t):
    n=int(input())
    a=[int(x) for x in input().split()]
    
    prefCnt=[[0 for _a in range(27)] for _b in range(n)]
    for j in range(1,27):
        cnts=0
        for i in range(n):
            if a[i]==j:
                cnts+=1
            prefCnt[i][j]=cnts
#    print(prefCnt)
    ans=0
    for outer in range(1,27):
        outerLen=0
        l=-1
        r=n
        while l<r:
            for inner in range(1,27):
                innerLen=getCnts(inner,l+1,r-1)
                ans=max(ans,outerLen*2+innerLen)
#                print('outer:{} inner:{} l:{} r:{} totalLength:{}'.format(outer,inner,l,r,outerLen*2+innerLen))
            l+=1
            while l<n and a[l]!=outer:
                l+=1
            r-=1
            while r>-1 and a[r]!=outer:
                r-=1
            outerLen+=1
#    print('here')
    print(ans)