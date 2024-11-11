
t = int(input())
while(t > 0):
  diff = int(input().split(" ")[1])
  s = input()
  balance = []
  currbal = 0
  inc = 0
  for idx in s:
    if(idx == '0'):
      currbal+=1
      balance.append(currbal)
    else:
      currbal-=1
      balance.append(currbal)
  inc = currbal
  ans = 0
  if(diff == 0):
    ans += 1
 
  for idx in balance:
    if(inc == 0):
      if(idx == diff):
        ans+=1
    else:
      if((diff - idx)%inc == 0 and (diff-idx)/inc > 0):
        ans+=1
  if(ans > 0 and inc == 0):
    print(-1)
  else:
    print(ans)
  t-=1


