A,B,C=map(int,input().split())
X=int(input())

while X>0:
  if B<A:
    B=2*B
  elif C<B:
    C=2*C
  X-=1

if A<B and B<C:
  print("Yes")
else:
  print("No")