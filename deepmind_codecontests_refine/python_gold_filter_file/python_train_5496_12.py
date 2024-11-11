m=int(input())
a=0
b=0
for i in range(m):
  d,c=map(int,input().split())
  a=a+d*c
  b=b+c
print((a-1)//9+b-1)