import itertools
def combination(n):
 m=0
 for i in itertools.product(range(10),repeat=4):
  (a,b,c,d)=i
  if a+b+c+d==n:
   m+=1
 return m

while True:
 try:
  n=int(input())
  combination(n)
 except EOFError:
  break