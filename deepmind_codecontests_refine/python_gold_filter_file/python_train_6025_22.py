n,l=map(int,input().split())
A=[int(i) for i in input().split()]
length,knot=A[0]+A[1],1
for i in range(n-2):
  if A[i+1]+A[i+2]>length:
    length=A[i+1]+A[i+2]
    knot=i+2
if length<l:
  print("Impossible")
else:
  print("Possible")
  for i in range(1,knot):
    print(i)
  for i in range(knot,n):
    print(n+knot-i-1)