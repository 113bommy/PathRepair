for _ in range(int(input())):
  n = int(input())
  arr = list(map(int, input().split()))
  count = 0

  if 0 in arr:
    for i in range(n):
      if arr[i] == 0:
        arr[i] = arr[i] + 1
        count += 1
  if sum(arr) > 0:
    print(count)
  else:
    while sum(arr) == 0:
      count += 1
      arr[-1] = arr[-1] + 1
    print(count)