def check1(x,arr,n,w):
  for i in range(n):
    x+=arr[i]
    if(x>w):
      return False
  return True
def check2(x,arr,n,w):
  for i in range(n):
    x+=arr[i]
    if(x<0):
      return False
  return True
n,w=(map(int,input().strip().split(' ')))
arr=list((map(int,input().strip().split(' '))))
low=0
high=w
ans=-1
ans1=-1
while(low<=high):
  mid=(low+high)//2
  if(check1(mid,arr,n,w)):
    ans=mid
    low=mid+1
  else:
    high=mid-1
low=w
high = 0

while(high<=low):
  mid=(low+high)//2
  if(check2(mid,arr,n,w)):
    low=mid-1
    ans1=mid
  else:
    high=mid+1
if(ans==-1 or ans1==-1 or ans<ans1):
  print(0)
else:
  print(ans-ans1+1)
