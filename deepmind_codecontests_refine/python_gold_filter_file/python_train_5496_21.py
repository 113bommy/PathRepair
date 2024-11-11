x=0;y=0
for _ in range(int(input())):
  d,c=map(int,input().split())
  x+=d*c
  y+=c
print(y-1+(x-1)//9)