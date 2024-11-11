
def main():

    t=int(input())
    allans=[]
    for _ in range(t):
        n,x=readIntArr()
        d=[]
        h=[]
        for _ in range(n):
            dd,hh=readIntArr()
            d.append(dd)
            h.append(hh)
        maxDamage=max(d)
        if x-maxDamage<=0:
            allans.append(0)
            continue
        maxDiff=-inf
        for i in range(n):
            maxDiff=max(maxDiff,d[i]-h[i])
        if maxDiff<=0:
            allans.append(-1)
            continue
        ans=1+(x-maxDamage+maxDiff-1)//maxDiff
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
 
def queryInteractive(i,j):
    print('? {} {}'.format(i,j))
    sys.stdout.flush()
    return int(input())
 
def answerInteractive(ans):
    print('! {}'.format(' '.join([str(x) for x in ans])))
    sys.stdout.flush()
 
inf=float('inf')
MOD=10**9+7
# MOD=998244353
 
 
for _abc in range(1):
    main()