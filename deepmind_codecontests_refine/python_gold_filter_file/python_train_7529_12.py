import math,string,itertools,fractions,heapq,collections,re,array,bisect,sys,random,time,queue,copy

sys.setrecursionlimit(10**7)
inf=10**20
mod=10**9+7
dd=[(-1,0),(0,1),(1,0),(0,-1)]
ddn=[(-1,0),(-1,1),(0,1),(1,1),(1,0),(1,-1),(0,-1),(-1,-1)]

def LI(): return [int(x) for x in sys.stdin.readline().split()]
def LI_(): return [int(x)-1 for x in sys.stdin.readline().split()]
def I(): return int(sys.stdin.readline())
def LS(): return sys.stdin.readline().split()
def S(): return input()

def main():
  n=I()

  l=[LI() for _ in range(n)]

  if n==1:
    return l[0][0]

  if n==3:
    sm=0
    for x in l:
      sm+=sum(x)
    return sm

  sm=0
  for x in l:
    sm+=sum(x)

  sm-=l[0][1]
  sm-=l[0][3]
  sm-=l[1][0]
  sm-=l[1][4]
  sm-=l[3][0]
  sm-=l[3][4]
  sm-=l[4][1]
  sm-=l[4][3]

  return sm

# main()
print(main())
