import sys
input = sys.stdin.readline

N,M = map(int,input().split())
Aorig = list(map(int,input().split()))
B = list(map(int,input().split()))

A = [0]
cnt = 0
for x in Aorig:
  cnt += x
  A.append(cnt)
print(A)

def bs(arr, x):
  l,r = 0, len(arr) - 1
  while l <= r:
    mid = l + (r - l) // 2
    if arr[mid] == x:
      return mid - 1
    elif arr[mid] < x:
      l = mid + 1
    else:
      r = mid - 1
  return r

for x in B:
  i = bs(A,x)
  print(i+1,x-A[i])