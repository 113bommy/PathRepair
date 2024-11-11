n=int(input())
arr=list(map(int,input().split()))
amax=max(arr)
amin=min(arr)
if amax-amin>=2:
  print('No')
elif amax-amin==0:
  flag=False
  for i in range(n):
    if arr[i]!=n-1:
      break
  else:
    flag=True
  for i in range(n):
    if 2*arr[i]>n:
      break
  else:
    flag=True
  if flag==True:
    print('Yes')
  else:
    print('No')
elif amax-amin==1:
  cnt1=0
  cnt2=0
  for i in range(n):
    if arr[i]==amax-1:
      cnt1+=1
    else:
      cnt2+=1
  if cnt1<amax and 2*(amax-cnt1)<=cnt2:
    print('Yes')
  else:
    print('No')