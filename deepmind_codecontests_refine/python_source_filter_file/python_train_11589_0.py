import sys
input=sys.stdin.readline
n=int(input())
keyframes=[]
ans=0
for i in range(n):
  a,c=map(int,input().split())
  ans+=c
  keyframes.append((a,1))
  keyframes.append((a+c,0))
keyframes.sort()
count=0
a,b=keyframes[0]
prev=a
for pos,t in keyframes:
  if t==1:
    if count==0:
      ans+=pos-prev
    count+=1
    prev=pos
  else:
    count-=1
    prev=pos
print(ans)