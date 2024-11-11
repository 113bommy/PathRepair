N,X=map(int,input().split())
L=[int(x) for x in input().split()]

C=D=0
while C<X:
  D+=L[C]
  if D>X:
    break;
  C+=1
print(C+1)
