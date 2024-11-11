a=int(input())
c=map(int, input().split())
d=0
for i in c:
  d=d+(i/100)
  
print((d/a)*100)
  