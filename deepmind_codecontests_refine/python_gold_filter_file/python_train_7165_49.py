n = int(input())
a = list(map(int,input().split()))
b = list(map(int,input().split()))
cou = 0
for j,k in zip(a,b):
  if j<k:
    cou += (k-j)//2
  elif j>k:
    cou -= (j-k)
if cou>=0:
  print("Yes")
else:
  print("No")