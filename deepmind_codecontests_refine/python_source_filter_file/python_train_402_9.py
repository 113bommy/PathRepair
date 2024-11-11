def main()
  while True:
    m = int(input())
    if not m: break
    seiza = []
    for i in range(m):
      seiza.append(list(map(int,input().split())))
    kijun = seiza.pop(0)
    
    n = int(input())
    hosi = []
    point = {}
    
    for i in range(n):
      x,y = map(int,input().split())
      point[x,y] = 1
      hosi.append([x,y])
  
    for a in hosi:
      dx,dy = a[0] - kijun[0], a[1] - kijun[1]
      for b in seiza:
        if not (b[0] + dx, b[1] + dy) in point:
          break
      else:
        print(dx,dy)
        break
main() 
