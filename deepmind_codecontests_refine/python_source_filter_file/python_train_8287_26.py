import math
def solve(n,a,b,c):
  n = n - 1
  if n == 0:
    return 0
  arr = sorted([a,b,c])
  min_val = arr[0]
  second_min_val = arr[1]
  if min_val == a or min_val == b:
    return min_val*n
  else:
    return min_val*n-1 + second_min_val

 
      
  

def main() :
  # n = int(input())
  # arr = list(map(int, input().split(' ')))
  arr = []
  for _ in range(4):
    arr.append(int(input()))
  print(solve(*arr))
main()
