def generate(tup,l):
  if l=="U":
    return (tup[0],tup[1]+1)
  elif l=="D":
    return (tup[0],tup[1]-1)
  elif l=="L":
    return (tup[0]-1,tup[1])
  else:
    return (tup[0]+1,tup[1])
def main():
  start=input().split()
  start[0]=int(start[0])
  start[1]=int(start[1])

  end=input().split()
  end[0]=int(end[0])
  end[1]=int(end[1])

  n=int(input())
  string=input()
  movement=[(0,0)]
  for x in range(n):
    movement.append(generate(movement[-1],string[x]))
  #print(movement)

  upper=10**15
  lower=0
  while upper-lower>1:
    middle=(upper+lower)//2
    loop=middle//n
    rem=middle%n
    distance=0
    distance+=abs(end[0]-(start[0]+loop*movement[-1][0]+movement[rem][0]))
    distance+=abs(end[1]-(start[1]+loop*movement[-1][1]+movement[rem][1]))
    #print(distance,middle)

    if distance<=middle:
      upper=middle
    else:
      lower=middle
  if upper>2*10**14:
    upper=-1
  print(upper)


main()
