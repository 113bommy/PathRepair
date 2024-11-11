n = int(input ())
for i in range(4):
  a,b,c,d = list(map(int,input().split()))
  if (((min(a,b) + min(c,d)))<= n):
    print ((i+1),min(a,b),(n-(min(a,b))))
    exit()
  elif i == 3:
    print ("-1")