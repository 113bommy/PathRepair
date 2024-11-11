def naiveSolve():
    
    
    
    return



def solve():
    
    
    
    return



def main():
    
    t=int(input())
    allans=[]
    for _ in range(t):
        n=int(input())
        s=input()
        if '0' in s:
            z=-1
            for i in range(n):
                if s[i]=='0':
                    z=i+1
                    break
            if z<=(n+1)//2:
                l1,r1,l2,r2=z,n,z+1,n
            else:
                l1,r1,l2,r2=1,z-1,1,z
        else:
            l1,r1,l2,r2=1,n-1,2,n
        allans.append((l2,r2,l1,r1))
        # first=s[l1-1:r1]
        # second=s[l2-1:r2]
        # firstVal=0
        # for x in first:
        #     firstVal*=2
        #     if x=='1': firstVal+=1
        # secondVal=0
        # for x in second:
        #     secondVal*=2
        #     if x=='1': secondVal+=1
        # print('firstVal:{} secondVal:{} n:{} l1:{} l2:{}'.format(firstVal,secondVal,n,len(first),len(second)))
    multiLineArrayOfArraysPrint(allans)
    
    return




import sys
# input=sys.stdin.buffer.readline #FOR READING PURE INTEGER INPUTS (space separation ok)
input=lambda: sys.stdin.readline().rstrip("\r\n") #FOR READING STRING/TEXT INPUTS.

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