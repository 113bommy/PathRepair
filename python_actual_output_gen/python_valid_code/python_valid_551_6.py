for _ in range(int(input())):
  l = int(input())
  r = input()
  if '0' in r:
    i=r.index('0')+1
    if i<=l//2+1:
      print(i,l,i+1,l)
    else:
      print(1,i,1,i-1)
  else:
    print(1,l//2,2,l//2+1)