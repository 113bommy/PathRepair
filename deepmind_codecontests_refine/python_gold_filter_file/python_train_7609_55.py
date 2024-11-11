
def prg():
  n = int(input())
  xs = sorted([int(x) for x in input().split()])
	
  #print(xs)
  start = xs[0]
  res = 0
  for x in xs:
    if x != start:
      res += x - start
      start += x - start + 1
    else:
	    start += 1
  
  print(res)
  
  
if __name__ == '__main__':
	prg()
