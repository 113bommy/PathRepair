n=int(input())

x=[]
y=[]

for i in range(n):
  s,t=map(int,input().split())
  x.append(s+t)
  y.append(s-t)

print(max(max(x)-min(x),max(y)-min(y)))
