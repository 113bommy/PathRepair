a,b=map(int,input().split())
x=max(a,b)
ans=7-x
xx=ans/6
flg=0
for i in range(1,6):
  for j in range(1,6):
    if i/j==xx:
      print(str(i)+"/"+str(j))
      flg=1
      break
  if flg==1:
    break
