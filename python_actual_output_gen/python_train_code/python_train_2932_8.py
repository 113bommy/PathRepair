import sys
N=int(input())
a=[int(i) for i in input().split()]
a.sort()

if a[N-1]-a[0]>1:
  print("No")
  sys.exit()
if a[0]==N-1:
  print("Yes")
  sys.exit()
if a[N-1]==1:
  print("Yes")
  sys.exit()
if a[0]==a[N-1]:
  if 2*a[0]<=N:
    print("Yes")
  else:
    print("No")
  sys.exit()

count=a.index(a[N-1])
if count+1<=a[N-1] and a[N-1]<=count+int((N-a[count])/2):
  print("Yes")
else:
  print("No")