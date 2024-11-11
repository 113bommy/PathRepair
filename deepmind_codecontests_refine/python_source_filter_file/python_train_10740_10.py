
def naiveSolve():
    
    
    
    return



def main():
    
    # Make a long line. Fulfill extras by filling in above and below the line.
    
    q=int(input())
    allans=[]
    for _ in range(q):
        ans=[]
        wb=readIntArr() # [white,black]
        avail=[[],[]] # [available white cells, black cells]
        if wb[1]>wb[0]: # start with black
            i=2; j=3
        else:
            i=j=2
        while wb[(i+j)%2]>0:
            wb[(i+j)%2]-=1
            ans.append([i,j])
            avail[(i+j+1)%2].append([i-1,j])
            avail[(i+j+1)%2].append([i+1,j])
            j+=1
        while avail[0] and wb[0]>0:
            ans.append(avail[0].pop())
            wb[0]-=1
        while avail[1] and wb[1]>0:
            ans.append(avail[1].pop())
            wb[1]-=1
        if wb[0]==wb[1]==0:
            allans.append(['YES'])
            allans.extend(ans)
        else:
            allans.append(['NO'])
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
 
for _abc in range(1):
    main()
