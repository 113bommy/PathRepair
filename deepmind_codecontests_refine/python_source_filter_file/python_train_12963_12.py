n=int(input())
a=[[],[]]
c=[]
for _ in[0]*n:
  z,*w=input().split()
  x,y=map(int,w)
  a[z=='F']+=[(x,y)]
  c+=[x,y]
r=0
for d in range(366):
  x=sum(x<=d<=y for x,y in a[0])
  y=sum(x<=d<=y for x,y in a[1])
  r=max(r,min(x,y))
print(r*2)