x=y=-1
for _ in range(int(input())):
  d,c=map(int,input().split())
  x+=d*c
  y+=c
print(y+x//9)