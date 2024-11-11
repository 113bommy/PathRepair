N=int(input())
m=int(N/11)
r=N-m
if r==0:
  print(2*m)
elif r<7:
  print(2*m+1)
else:
  print(2*m+2)