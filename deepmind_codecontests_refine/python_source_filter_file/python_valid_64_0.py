def naiveSolve():
    
    
    
    return

class UnionFind:
    def __init__(self, n):
        self.parent = list(range(n))
    def find(self, a): #return parent of a. a and b are in same set if they have same parent
        acopy = a
        while a != self.parent[a]:
            a = self.parent[a]
        while acopy != a: #path compression
            self.parent[acopy], acopy = a, self.parent[acopy]
        return a
    def union(self, a, b): #union a and b
        self.parent[self.find(b)] = self.find(a)

def main():
    
    n,m1,m2=readIntArr()
    
    uf1=UnionFind(n+1)
    uf2=UnionFind(n+2)
    
    for _ in range(m1):
        u,v=readIntArr()
        uf1.union(u,v)
    for _ in range(m2):
        u,v=readIntArr()
        uf2.union(u,v)
    
    # eventually 1 of the forests will only have 1 component
    # order of merging does not affect number of edges added
    # try to merge everything to 1 of both forests
    # start by using same nodes where u is not merged to 1 for both forests
    
    ans=[]
    for u in range(1,n+1):
        if uf1.find(1)!=uf1.find(u) and uf2.find(1)!=uf2.find(u):
            ans.append((1,u))
            uf1.union(1,u)
            uf2.union(1,u)
    
    # now, if u is not matched to 1 in forest 1, it must be matched to 1
    # in forest 2. same logic for u not matched to 1 in forest 2.
    # any u1 not matched to 1 in forest 1 can be matched to u2 not matched
    # to 1 in forest 2.
    u1=1
    u2=1
    while True:
        while u1<=n and uf1.find(1)==uf1.find(u1):
            u1+=1
        while u2<=n and uf2.find(1)==uf2.find(u2):
            u2+=1
        if u1<=n and u2<=n:
            ans.append((u1,u2))
            uf1.union(u1,1) # can also union(u1,u2)
            uf2.union(u2,2)
        else:
            break
    print(len(ans))
    multiLineArrayOfArraysPrint(ans)
    
    
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
MOD=998244353

from math import gcd,floor,ceil
# from math import floor,ceil # for Python2
 
for _abc in range(1):
    main()