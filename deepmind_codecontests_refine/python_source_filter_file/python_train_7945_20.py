from collections import defaultdict

def solution(array):
  xfreq = defaultdict(list)
  yfreq = defaultdict(list)
  for p in array: 
    x, y = p
    xfreq[x].append(p)
    yfreq[y].append(p)
  num_of_points = 0
  for p in array: 
    neighbours = 0 

    for n in xfreq[p[0]]:
      if (n[1] > p[1]):
        neighbours += 1
        break
    for n in xfreq[p[0]]:
      if (n[1] > p[1]):
        neighbours += 1
        break
    for n in yfreq[p[1]]:
      if (n[0] < p[0]):
        neighbours += 1
        break 
    for n in yfreq[p[1]]:
      if (n[0] >  p[0]):
        neighbours += 1
        break 
    if neighbours == 4: 
      num_of_points += 1
  return num_of_points

if __name__ == "__main__":
  n = int(input())
  points = [list(map(int, input().split())) for _ in range(n)]

  print(solution(points))