N=int(input())
if N>2:
  n=input().split()
  l=0
  p=0
  j=0
  n=sorted(n,key=lambda n:int(n))
  for i in range (N):
    l=l+int(n[i])
  for o in range (0,N-2):
    p=int(n[o])+p
    s=l-p
    j=j+s
  print(j+2*l)
 
if N<=2:
  n=input().split()
  l=0
  for i in range(N):
    l=l+int(n[i])
  print(l*N)
