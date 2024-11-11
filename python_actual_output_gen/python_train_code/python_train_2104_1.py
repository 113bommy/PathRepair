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