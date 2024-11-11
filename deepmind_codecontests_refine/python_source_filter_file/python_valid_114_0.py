
def naiveSolve():
    
    
    
    return



def solve():
    
    
    
    return



def main():
    
    def calculateTotal(build):
        ans=0
        for i in range(n):
            ans+=strength[i][build[i]-1]
        return ans
    
    n=int(input())
    strength=[[] for _ in range(n)]
    
    for i in range(n):
        temp=readIntArr()
        temp.pop(0)
        strength[i]=temp
    
    bannedBuilds=set()
    bannedArr=[]
    m=int(input())
    for _ in range(m):
        build=readIntArr()
        bannedArr.append(build)
        bannedBuilds.add(hash(tuple(build)))
    
    initialBuild=[len(x) for x in strength]
    if hash(tuple(initialBuild)) not in bannedBuilds:
        oneLineArrayPrint(initialBuild)
        return
    
    # explore from bannedBuilds
    bestScore=0
    bestAns=[]
    for build in bannedArr:
        for i in range(n):
            if build[i]-1>=0:
                build[i]-=1
                if hash(tuple(build)) not in bannedBuilds:
                    score=calculateTotal(build)
                    if score>bestScore:
                        bestScore=score
                        bestAns=build.copy()
                build[i]+=1
    
    oneLineArrayPrint(bestAns)

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
 
def queryInteractive(x):
    print('{}'.format(x))
    sys.stdout.flush()
    return int(input())
 
def answerInteractive(ans):
    print('! {}'.format(ans))
    sys.stdout.flush()
 
inf=float('inf')
# MOD=10**9+7
# MOD=998244353

from math import gcd,floor,ceil
# from math import floor,ceil # for Python2
 
for _abc in range(1):
    main()