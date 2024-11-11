t=int(input())
for i in range(t):
  l=[int(i) for i in input().split()]
  if (abs(l[0]-l[1])%2==1):
    print(-1)
  elif (l[0]==l[1])and (l[0]==0):
    print(0)
  elif (l[0]==l[1]):
    print(1)
  else :
    print(2)