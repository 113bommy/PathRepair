import math
def solve(n,a,b):
  
  if b< 0:
    res=(n-(-1*b%n))+a
  else:  
    res = b%n + a
  return res if res < n else res-n

def main() :
  arr = list(map(int, input().split(' ')))
  # arr = []
  # for _ in range(3):
  #   arr.append(input())
  print(solve(*arr))
main()
