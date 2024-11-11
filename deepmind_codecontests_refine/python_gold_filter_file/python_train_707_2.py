import math
K=int(input())
k=2
m=0
def D(x):
  s=str(x)
  array=list(map(int,list(s)))
  return sum(array)
N=1
S=1
a=0
print(1)
while k<=K:
  N+=10**a
  S=D(N)
  if a<math.log10(N/S):
    a+=1
    N=(N//10**a+1)*10**a-1
  S=D(N)
  print(N)
  k+=1
    
    
