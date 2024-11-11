def func():
  n = int(input())
  arr = list(map(int, input().split()))
  if n==0:
    return 0
  if sum(arr)<n:
    return -1
  arr.sort()
  arr.reverse()
  c=0
  for i in range(12):
    c+=arr[i]
    if c>=n:
      return i+1
  

print(func())