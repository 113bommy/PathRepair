x=int(input())
mx=1
for i in range(2,32):
  p=2
  while i**p<=x:
    if i**p > mx:
      mx = i**p
      p+=1
print(mx)