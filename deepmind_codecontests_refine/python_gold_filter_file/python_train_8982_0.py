for i in range(int(input())):
  w ,h ,n = [int(j) for j in input().split()]
  bo = False
  co = 0 
  while True:
    if w%2==0:
      w //=2
      co += 1
    else:
      if h%2==0:
        h //=2
        co += 1
      else:
        break
  if (pow(2,co))>=n or n==1:
    print("YES")
  else:
    print("NO")
