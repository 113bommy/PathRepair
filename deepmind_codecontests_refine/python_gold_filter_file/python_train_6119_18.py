n=int(input())
for i in range(360):
  if (i*n+n)%360==0:
    print(i+1)
    break