n,l=map(int,input().split())
arr=list(map(int,input().split()))
pos=0
tmp=0
for i in range(n-1):
  if (arr[i]+arr[i+1])>tmp:
    pos=i
    tmp=(arr[i]+arr[i+1])
if tmp<l:
  print('Impossible')
else:
  print('Possible')
  ans=[]
  for i in range(pos):
    ans.append(i+1)
  for i in range(n-1,pos+1,-1):
    ans.append(i)
  ans.append(pos+1)
  for i in range(n-1):
    print(ans[i])