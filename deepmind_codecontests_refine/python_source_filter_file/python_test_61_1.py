def naiveSolve():
    
    
    
    return



def solve():
    
    
    
    return



def main():
    
    t = int(input())
    allans = []
    for _ in range(t):
        n = int(input())
        a = []; b = []
        aCnt = [0] * (n + 1); bCnt = [0] * (n + 1)
        for __ in range(n):
            aa, bb = readIntArr()
            a.append(aa); b.append(bb)
            aCnt[aa] += 1; bCnt[bb] += 1
        ans = (n * (n - 1) * (n - 2)) // 6
        # print('initial ans:{}'.format(ans))
        badCnts = 0
        for i in range(n):
            badCnts += (aCnt[a[i]] - 1 + bCnt[b[i]] - 1)
            # print('i:{} change:{}'.format(i, (aCnt[a[i]] - 1 + bCnt[b[i]] - 1)))
        badCnts //= 3
        ans -= badCnts
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
 
def queryInteractive(x,y):
    print('? {} {}'.format(x,y))
    sys.stdout.flush()
    return int(input())
 
def answerInteractive(i1,j1,i2,j2):
    print('! {} {} {} {}'.format(i1,j1,i2,j2))
    sys.stdout.flush()
 
inf=float('inf')
# MOD=10**9+7
# MOD=998244353

from math import gcd,floor,ceil
# from math import floor,ceil # for Python2
 
for _abc in range(1):
    main()