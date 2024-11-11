T = int(input())
infinityClockArrs = []
def infinityClock(arr, k):  
  # k is num of operations
  sortedArr = sorted(arr)  
  if k%2 == 0:
    d = sortedArr[0]
    for idx in range(len(arr)):
      arr[idx] = d-arr[idx]
  else:
    d = sortedArr[len(sortedArr)-1]
    for idx in range(len(arr)):
      arr[idx] = d-arr[idx]
  return list(map(str, arr))


for t in range(T):
  arrAndOperationSize = list(map(int, input().split()))
  arr = list(map(int, input().split()))
  infinityClockArrs.append(infinityClock(arr, arrAndOperationSize[1]))

for infinityClockArr in infinityClockArrs:
  print(' '.join(infinityClockArr))