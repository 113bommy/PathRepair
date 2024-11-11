N = int(input())
s = 0
for i in range(1,N,2):
  t = 0
  for j in range(1,i+1,2):
    if not i%j:
      t+=1
  if t==8:
    s+=1

print(s)