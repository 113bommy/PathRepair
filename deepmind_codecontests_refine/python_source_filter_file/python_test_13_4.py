for _ in range(int(input())):
  l = input()
  p = len(l.split('A'))-1
  q = len(l.split('C'))-1
  r = len(l.split('B'))-1
  if q==p+r:
    print("YES")
  else:
    print("NO")