a=int(input())
b=int(input())
c=int(input())
x=int(input())
x_dash=x//50
cnt=0
for i in range(1,a+1):
  for j in range(1,b+1):
    k=x_dash-10*i-2*j
    if 0<=k<=c:
      cnt+=1
print(cnt)