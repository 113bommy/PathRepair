n=int(input())
a=[int(x) for x in input().input()]
flg=0
for x in a:
  if x%2==0 and x%3 and x%5:
    flg=1
if flg:
  print("DENIED")
else:
  print("APPROVED")