a=int(input())
b=int(input())
c=int(input())
X=int(input())


x=X/50

count=0

for i in range(a+1):
  for l in range(b+1):
    if 0<=x-a*10-b*2<=c:
      count+=1
      
print(count)