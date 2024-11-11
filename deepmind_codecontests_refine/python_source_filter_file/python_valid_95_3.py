
def naiveSolve():
    
    
    
    return



def solve(s,n):
    
    # break down to 10s
    m=1
    arr=[]
    while s>0:
        x=s%10
        for _ in range(x):
            arr.append(m)
        s//=10
        m*=10
    # print(arr)
    while len(arr)<n:
        smallestNonOne=1e9
        for x in arr:
            if x<smallestNonOne and x>1:
                smallestNonOne=x
        arr.remove(smallestNonOne)
        for _ in range(10):
            x=smallestNonOne//10
            arr.append(x)
    while len(arr)>n:
        back=arr.pop()
        arr[-1]+=back
    return arr
    
    return 

def main():
    
    t=int(input())
    allans=[]
    for _ in range(t):
        allans.append(solve(*readIntArr()))
    multiLineArrayOfArraysPrint(allans)
    
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