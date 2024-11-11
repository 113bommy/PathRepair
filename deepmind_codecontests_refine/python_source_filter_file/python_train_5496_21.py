x=0;y=0
for _ in range(int(input())):
  d,c=map(int,input().split())
  x+=d*c
  y+=c
print(y-2+x//9)