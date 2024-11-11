m=int(input())
counter=0
s=0
for i in range(m):
  d,c=map(int,input().split())
  counter+=d*c
  s+=c
print(s-1+(counter-1)//9)