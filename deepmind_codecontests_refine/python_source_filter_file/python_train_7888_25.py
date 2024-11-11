n=int(input())
l=[]
for i in range(n):
  x,y=map(int,input().split())
  l.append([x-y+1,x+y-1])
count=0
l=sorted(l)
l=l[::-1]
count+=1
now=l[0][0]
for i in range(1,n):
  if now>l[i][1]:
    now=l[i][0]
    count+=1
  else:
    pass
print(count)