i=0
a,b,c = map(int,input().split())
for x in range(a+1,b):
  if c % x == 0: i+=1
print(str(i))
