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
  s=S()

  ans=0
  ans_str=''
  for i in range(n//2):
    ac=bc=0
    x=''
    for j in range(i*2,i*2+2):
      x+=s[j]
      if x=='a':
        ac+=1
      else:
        bc+=1

    if abs(ac-bc)==2:
      ans+=1

      ans_str+='ab'

    else:
      ans_str+=x

  print(ans)
  print(ans_str)

main()
# print(main())
