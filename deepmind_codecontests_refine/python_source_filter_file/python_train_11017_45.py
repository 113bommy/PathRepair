N = int(input())
A = list(map(int, input().split()))
max_A = -10**9
max_num = 0
min_A = 10**9
min_num = 0
for i in range(N):
  if(max_A < A[i]):
    max_A = A[i]
    max_num = i
  if(min_A > A[i]):
    min_A = A[i]
    min_num = i
if(max_A > 0 and min_A < 0):
  if(abs(max_A) >= abs(min_A)):
    print(2*N-1)
    for i in range(N):
      A[i] += max_A
      print(max_num+1, i+1)
    for i in range(N-1):
      print(i+1, i+2)
  else:
    print(2*N-1)
    for i in range(N):
      A[i] += min_A
      print(min_num+1, i+1)
    for i in range(N-1, 0, -1):
      print(i+1, i)
elif(min_A > 0):
  print(N-1)
  for i in range(N-1):
    print(i+1, i+2)
elif(max_A < 0):
  print(N-1)
  for i in range(N-1, 0, -1):
    print(i+1, i)
else:
  print(0)