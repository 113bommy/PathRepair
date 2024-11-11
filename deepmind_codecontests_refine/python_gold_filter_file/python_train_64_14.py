n = int(input())
arr = list(map(int,input().split()))
h = 1
if arr[n-1]-1<500000:
 print(arr[n-1]-1)
elif arr[0]>500000:
 print(1000000-arr[0])
else:
 for i in range(n):
  if arr[i]>500000:
    h  = i
    break
 if arr[h-1]>1000000-arr[h]:
  print(arr[h-1]-1)
 else:
  print(1000000-arr[h])
