=int(input())
b=int(input())
c=int(input())
m=int(input())
s=0
for i in range(a+1):
  for j in range(b+1):
    x,y=divmod(m-i*500-j*100,50)
    if y==0 and 0<=x<=c:
      s+=1
print(s)