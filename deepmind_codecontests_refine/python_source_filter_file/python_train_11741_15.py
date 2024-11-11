N = int(input())
A = list(map(int, input().split()))
bottom = sum(A)

if bottom == 0:
  print(-1)
  exit()
 
ret = 1
children = 1 - A[0]
bottom -= A[0]
 
for i in range(N):
    children = children * 2 - A[i+1]
    if children <= -1:
      ret = -1
      break
    
    bottom -= A[i+1]
    if children >= bottom:
      children = bottom
    ret += children + A[i+1]
print(ret)
