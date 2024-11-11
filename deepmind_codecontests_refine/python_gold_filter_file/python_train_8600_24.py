q = [[0,0], [9,1], [6,0], [15,1]]
for i in range(int(input())):
  a = int(input())
  whole = a//4
  que = a%4
  print(-1 if a < q[que][0] else whole - q[que][1])