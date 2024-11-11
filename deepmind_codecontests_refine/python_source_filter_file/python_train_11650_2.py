while 1:
 n=int(input())
 if n==0:break
 d={}
 for _ in[0]*n:
  k,v=input().strip().split()
  d[k]=v
 for _ in[0]*int(input()):
  e=input()
  print(d[e]if e in d else e,end='')
 print()
