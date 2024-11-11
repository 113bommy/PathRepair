n=int(input())
l=[]
l1=[]
for i in range(n):
  l1=list(map(int,input().split()))
  l1=l1[::-1]
  l.append(l1)      
l=sorted(l)
for i in range(101):
  for j in range(101):
    b=True
    h=abs(i-l[-1][2])+abs(j-l[-1][1])+l[-1][0]
    for i in range(n-1):
      if max(h-abs(i-l[-2-i][2])-abs(j-l[-2-i][1]),0)!=l[-2-i][0]:
        b=False
    if b:
      print(i,j,h)
      break