import sys
sys.setrecursionlimit(1000000)
n=int(input())


def dfs(s,x):
  if len(s)==n:
    print(s)
  else:
    for i in range(x):
      dfs(s+chr(ord("a")+i),x)
    dfs(s+chr(ord("a")+x),x+1)  
dfs("a",1) 
  