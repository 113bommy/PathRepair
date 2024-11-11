def naiveSolve():
    
    
    
    return



def solve():
    
    
    
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

def northWall(x):
    return (x&8)>0
def eastWall(x):
    return (x&4)>0
def southWall(x):
    return (x&2)>0
def westWall(x):
    return (x&1)>0

def main():
    
    n,m=readIntArr()
    grid=[]
    for _ in range(n):
        grid.append(readIntArr())
    uf=UnionFind(n*m)
    for i in range(n):
        for j in range(m):
            if j+1<m and eastWall(grid[i][j])==westWall(grid[i][j+1])==False:
                uf.union(i*m+j,i*m+j+1)
            if i+1<n and southWall(grid[i][j])==northWall(grid[i+1][j])==False:
                uf.union(i*m+j,(i+1)*m+j)
    
    sz=[False]*(n*m)
    for i in range(n):
        for j in range(m):
            sz[uf.find(i*m+j)]+=1
    rooms=[]
    for x in range(n*m):
        if sz[x]>0:
            rooms.append(sz[x])
    rooms.sort(reverse=True)
    oneLineArrayPrint(rooms)
    
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