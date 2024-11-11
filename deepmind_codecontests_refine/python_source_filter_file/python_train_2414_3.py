def isAll9s(s):
    return set(s)=='9'

def add1(s):
    n=len(s)
    arr=[int(x) for x in s]
    for i in range(n-1,-1,-1):
        if arr[i]==9:
            arr[i]=0
        else:
            arr[i]+=1
            break
    return ''.join([str(x) for x in arr])

def main():
    
    L=int(input())
    A=input()
    
    n=len(A)
    if L>n:
        ans='1'+('0'*(L-1))
    else: # n>=L
        if n%L==0 and isAll9s(A)==False: # finalLen is n
            m=n//L
            # ans is either m*(1st L) or m*(1st L + 1)
            firstL=A[:L]
            ans=m*firstL
            if ans<=A: # need to add 1
                firstL2=add1(firstL)
                ans=firstL2*m
        else: # finalLen must be > n
            finalLen=n+L
            ans=('1'+('0'*(L-1)))*(finalLen//L)
    
    print(ans)
    
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