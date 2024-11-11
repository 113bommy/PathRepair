n  = int(input())
import bisect

def f(arr):
  arr.sort()
  part1 = []
  part2 = []
  
  if len(arr) % 4 == 0:
    part1 = [arr[0], arr[1]]
    for i in range(2, len(arr), 2):
      part1.append(arr[i])
      part2.append(arr[i+1])
  
  else:   
    for i in range(0, len(arr), 2):
      part1.append(arr[i])
      part2.append(arr[i+1])
 
  m1 = part1[len(part1)//2]
  m2 = part2[len(part2)//2]
  
  return abs(m1-m2)    
  
for _ in range(n):
  input()
  arr = list(map(int, input().split()))
  #print('array', arr)
  print(f(arr))