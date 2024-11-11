X=int(input())
K=0
a=0
while True:
  a+=X
  K+=1
  if a%360==0:
    break
print(K)