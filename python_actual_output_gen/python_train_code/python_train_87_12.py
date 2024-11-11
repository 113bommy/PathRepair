t = int(input())

for o in range(t):
  n = int(input())
  if n==1:
    print(0)
    continue
  count = 0
  while n%3==0:
    n //= 3
    count += 1
  c = 0
  while n%2==0:
    n //= 2
    c +=1
  if n%6==0 and c <=count:
    print( 2*count-c)
  else:
    print(-1)