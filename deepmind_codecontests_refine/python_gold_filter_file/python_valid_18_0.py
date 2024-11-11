
def naiveSolve():
    
    
    
    return



def main():
    
    t=int(input())
    allans=[]
    for _ in range(t):
        n,k=readIntArr()
        lines=[]
        remaining=set(range(1,2*n+1))
        # there is a cross iff (assuming x<y), x1<x2<y1<y2 or x2<x1<y2<y1
        for __ in range(k):
            x,y=readIntArr()
            x,y=min(x,y),max(x,y)
            lines.append((x,y))
            remaining.remove(x)
            remaining.remove(y)
        # match each remaining x to a y which is half the remaining length ahead
        m=len(remaining)
        remaining=sorted(remaining)
        for i in range(m//2):
            lines.append((remaining[i],remaining[i+m//2]))
        def crosses(x1,y1,x2,y2):
            return x1<x2<y1<y2 or x2<x1<y2<y1
        ans=0
        # print(lines)
        for i in range(n):
            # cnts=0 ## TEST
            for j in range(i+1,n):
                x1,y1=lines[i]
                x2,y2=lines[j]
                if crosses(x1,y1,x2,y2):
                    ans+=1
                    # cnts+=1 ##
            # print('i:{} cnts:{}'.format(i,cnts))
        allans.append(ans)
    multiLineArrayPrint(allans)
    
    return



import sys
input=sys.stdin.buffer.readline #FOR READING PURE INTEGER INPUTS (space separation ok)
# input=lambda: sys.stdin.readline().rstrip("\r\n") #FOR READING STRING/TEXT INPUTS.

def oneLineArrayPrint(arr):
    print(' '.join([str(x) for x in arr]))
def multiLineArrayPrint(arr):
    print('\n'.join([str(x) for x in arr]))
def multiLineArrayOfArraysPrint(arr):
    print('\n'.join([' '.join([str(x) for x in y]) for y in arr]))
 
def readIntArr():
    return [int(x) for x in input().split()]
# def readFloatArr():
#     return [float(x) for x in input().split()]
 
def makeArr(defaultValFactory,dimensionArr): # eg. makeArr(lambda:0,[n,m])
    dv=defaultValFactory;da=dimensionArr
    if len(da)==1:return [dv() for _ in range(da[0])]
    else:return [makeArr(dv,da[1:]) for _ in range(da[0])]
 
def queryInteractive(l,r):
    print('? {} {}'.format(l,r))
    sys.stdout.flush()
    return int(input())
 
def answerInteractive(x):
    print('! {}'.format(x))
    sys.stdout.flush()
 
inf=float('inf')
MOD=10**9+7
# MOD=998244353

from math import gcd,floor,ceil
# from math import floor,ceil # for Python2
 
for _abc in range(1):
    main()