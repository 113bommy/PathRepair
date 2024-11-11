N = int(input())
A1 = list(map(str,input().split()))
A2 = A1[:]

def bubbleSort(A, N):
 flag = 0
 i = 0
 while flag == 0:
  flag = 1
  for j in range(N-1, i, -1):
   if A[j][1] < A[j-1][1]:
    A[j], A[j-1] = A[j-1], A[j]
    flag = 0
  i += 1
 return A

def selectSort(A, N):
 for i in range(N):
  minj = i
  for j in range(i, N):
   if A[j][1] < A[minj][1]:
    minj = j
  if A[i][1] != A[minj][1]:
   A[i], A[minj] = A[minj], A[i]
 return A

def stable(Ab, As, N):
 for i in range(N):
  if Ab[i] != As[i]:
   return False
 return True

bubbleSort(A1, N)
selectSort(A2, N)
print(" ".join(map(str, A1)))
print("Stable")
print(" ".join(map(str, A2)))
if stable(A1, A2, N):
 print("Stable")
else:
 print("Not Stable")