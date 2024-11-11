from collections import Counter
n=int(input())
a=list(map(int,input().split()))
x=max(a)
c=Counter(a)
flg=1
for i in range((x+1)//2,x+1):
  if i == (x+1)//2:
    if x%2==0:
      if c[i]==0:
        flg=0
    else:
      if c[i]<=1:
        flg=0
  else:
    if c[i]<=1:
      flg=0
if flg:
  print("Possible")
else:
  print("Impossible")