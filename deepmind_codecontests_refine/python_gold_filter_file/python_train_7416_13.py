li = [int(input()) for _ in range(int(input()))]
n = 10 ** 9
arr = [0] * (10 ** 5)
arr[0] = 2
count = 5
i = 0
while arr[i] + count < n:
  arr[i + 1] = arr[i] + count
  count += 3
  i += 1
l = i + 1
arr = arr[:l]
arr = arr[::-1]    
    
for n in li:  
  i = 0
  count = 0
  while i < l:
    if n <= 1:
      print(count)
      break
    elif arr[i] <= n:
      n -= arr[i]
      count += 1
    else:
      i += 1