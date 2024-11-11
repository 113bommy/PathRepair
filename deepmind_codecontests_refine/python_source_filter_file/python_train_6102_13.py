n=int(input())
arr=list(map(int,input().split()))
if n==1:
  if n%2==0:
    print("No")
  else:
    print("Yes")
elif len(arr)%2==0:
  print("No")
elif arr[0]%2==0 or arr[len(arr)-1]%2==0:
  print("No")
else:
  print("Yes")
  """
  arr1=[]
  k=0
  while k<len(arr):
    if arr[k]%2==1:
      arr1.append(1)
    else:
      arr1.append(0)
      k+=1
      while k<len(arr) and arr[k]%2!=1:
        k+=1
      k-=1 
    k+=1
  print(arr1)
  flag=0
  count=0
  last=-1
  k=0
  while k<len(arr1):
    if arr1[k]==0 and last=k-2:
      flag=1 
      break
    else:
      count+=1 
      last=k
    k+=1
  """