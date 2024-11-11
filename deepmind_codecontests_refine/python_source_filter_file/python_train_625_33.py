i=0
a,b,c = map(int,input().split())
for x in range(a,b):
  if c % x == 0: i+=1
print(i)
