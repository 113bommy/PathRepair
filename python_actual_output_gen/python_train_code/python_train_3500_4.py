n=int(input())
A=[0]*(n+1)
a=round(n**0.5)+2
for x in range(1,a):
  for y in range(1,a):
    for z in range(1,a):
      b=x*x+y*y+z*z+x*y+y*z+z*x
      if b<n:
        A[b]+=1
for i in range(1,n+1):
  print(A[i])