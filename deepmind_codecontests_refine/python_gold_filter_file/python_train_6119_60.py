X=int(input())
for i in range(1,361):
  if (X*i)%360==0:
    print(i)
    break