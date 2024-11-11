N=int(input())
k=N//11
s=N-(k*11)
if s==0:
  print(k*2)
elif s<=6:
  print(2*k+1)
else:
  print(2*k+2)