import math,itertools,fractions,heapq,collections,bisect,sys,queue,copy

sys.setrecursionlimit(10**7)
inf=10**20
mod=10**9+7
dd=[(-1,0),(0,1),(1,0),(0,-1)]
ddn=[(-1,0),(-1,1),(0,1),(1,1),(1,0),(1,-1),(0,-1),(-1,-1)]

def LI(): return [int(x) for x in sys.stdin.readline().split()]
# def LF(): return [float(x) for x in sys.stdin.readline().split()]
def I(): return int(sys.stdin.readline())
def F(): return float(sys.stdin.readline())
def LS(): return sys.stdin.readline().split()
def S(): return input()

def main():
  n=I()
  ans=[]

  l=LI()
  for x in l:
    if 15<=x<21:
      ans.append('YES')
    else:
      a=[]
      for i in range(15,22):
        a.append(x-i)

      f=False
      for y in a:
        if y!=0 and y%14==0:
          f=True
          break
      if f:
        ans.append('YES')
        continue
      else:
        ans.append('NO')

  for x in ans:
    print(x)

main()
# print(main())
