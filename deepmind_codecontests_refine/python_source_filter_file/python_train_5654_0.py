def check(ans):
    currmax=ans[0]
    p=0
    oh=0
    wow=0
    for x in ans:
        if x>1:
            if x>p:
                wow+=1
            elif x>currmax:
                oh+=1
        currmax=max(currmax,x)
        p+=x
    print('a:{} b:{}'.format(oh,wow))
        
def main():
    
    n,a,b=readIntArr()
    
    ok=True
    ans=[1]*n
    if a==0 and b==0:
        pass
    elif a>0 and b==0:
        for i in range(2,n):
            if a>0:
                ans[i]=ans[i-1]+1
                a-=1
        if b>0:
            ok=False
    else: # a>=0 and b>0
        for i in range(1,n):
            if b>0:
                ans[i]=2**i
                b-=1
            elif a>0:
                ans[i]=ans[i-1]+1
                a-=1
        if not (a==0 and b==0):
            ok=False
    if ok:
        oneLineArrayPrint(ans)
        # check(ans)
    else:
        print(-1)
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