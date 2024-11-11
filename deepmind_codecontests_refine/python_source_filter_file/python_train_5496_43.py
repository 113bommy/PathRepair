m=int(input())
s,c=0,0
for i in range(m):
  d,c=map(int,input().split())
  s+=d*c
  k+=c
print(k-1+(s-1)//9)