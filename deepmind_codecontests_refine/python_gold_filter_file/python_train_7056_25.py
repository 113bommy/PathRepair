s=str(input())
q=int(input())
now = 0
mae,usiro="",""
for _ in range(q):
  lis = list(map(str,input().split()))
  if int(lis[0]) == 1:
    now = (now+1)%2
  else:
    if (int(lis[1])+now)%2 == 1:
      mae = lis[2]+mae
    else:
      usiro= usiro +lis[2]
s = mae+s+usiro
if now ==0:
  print(s)
else:
  print(s[::-1])
    
  
