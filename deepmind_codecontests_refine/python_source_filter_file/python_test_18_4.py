
def naiveSolve():
    
    
    
    return



def solve():
    
    
    
    return



def main():
    
    t=int(input())
    allans=[]
    for _ in range(t):
        n,d=readIntArr()
        a=readIntArr()
        if len(set(a))==1:
            if a[0]==1:
                allans.append(-1)
            else:
                allans.append(0)
            continue
        if d==n:
            allans.append(0)
            continue
        
        eventualVal=[1]*n
        nSteps=[-1]*n
        vi=[False]*n
        
        for i,x in enumerate(a):
            if x==0:
                eventualVal[i]=0
                nSteps[i]=0
                vi[i]=True
        for i in range(n):
            if not vi[i]:
                j=(i+d)%n
                steps=1
                while i!=j and a[j]==1: # keep going until either cycled or found a 0
                    j=(j+d)%n
                    steps+=1
                finalVal=a[j]
                
                j=i
                while steps>0:
                    eventualVal[j]=finalVal
                    vi[j]=True
                    nSteps[j]=steps
                    steps-=1
                    j=(j+d)%n
        
        if 1 in eventualVal:
            allans.append(-1)
        else:
            allans.append(max(nSteps))
                
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
