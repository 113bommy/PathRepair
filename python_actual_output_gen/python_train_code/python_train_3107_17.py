N = int(input())
A = [int(input()) for _ in range(N)]

def solve() :
  if A[0] != 0 :
    return -1

  for i in range(1, N) :
    if A[i] - A[i-1] > 2:
      return -1

  ret = 0
  for i in range(1, N) :
    if A[i] == 0 :
      continue

    ret += 1
    if A[i] != A[i-1] + 1 :
      ret += A[i] - 1
  
  return ret

print(solve())