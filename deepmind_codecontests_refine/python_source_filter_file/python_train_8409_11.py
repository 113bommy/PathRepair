x=int(input())
if x==2:
  print(2)
  exit()

for i in range(x+1,x*100):
  for j in range(2,int(x**0.5)+2):
    if i%j==0:
      break
  else:
    print(i)
    exit()
