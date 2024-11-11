def merge(A, left, mid, right):
  global count
  L = A[left:mid] + [10**9 + 1]
  R = A[mid:right] + [10**9 + 1]
  
  i = 0
  j = 0

  for k in range(left, right):
    if L[i] <= R[j]:
      A[k] = L[i]
      i += 1
    else:
      A[k] = R[j]
      j += 1
  count += right - left

def mergeSort(A, left, right):
  if left + 1 < right:
    mid = (left + right) // 2
    mergeSort(A, left, mid)
    mergeSort(A, mid, right)
    merge(A, left, mid, right)

N = int(input())
A = list(map(int, input().split()))
count = 0
mergeSort(A, 0, N)
print(*A)
print(count)
    