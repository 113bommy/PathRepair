n = int(input())
arr = [int(i) for i in input().split(' ')]
count = 0
while(count < n-1):
  count = 0
  arr.sort()
  for i in range(1, n):
    if(arr[i] > arr[i-1] and arr[i-1] != 0):
      arr[i] -= arr[i - 1]
    else:
      count += 1
  print(arr)
print(sum(arr))