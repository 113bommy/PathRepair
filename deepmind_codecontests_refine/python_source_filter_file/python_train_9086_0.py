import math
def inp():
    return(int(input()))
def inlt():
    return(list(map(int,input().split())))
def insr():
    s = input()
    return(list(s[:len(s) - 1]))
def invr():
    return(map(int,input().split()))
t=int(input())
k=0
while(k != t):
  a,b,c,d=inlt()
  lati=[a , b , c , d]
  lati.sort()
  a=lati[0]
  b=lati[1]
  c=lati[2]
  d=lati[3]
  if a != b and c !=d:
    x=c*(b-a)
  elif a==b and c !=d:
    x=c*a
  elif c==d and a!=b:
    x=(b-a)*c
  elif a==b and c==d:
    x=a*c
  elif b==c:
    x=a*b
  print(x)
  k=k+1