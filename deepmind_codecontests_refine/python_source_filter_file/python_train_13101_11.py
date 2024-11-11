n,c,k=map(int,input().split())
t=[int(input()) for _ in [0]*n]
t.sort()
t=t+[0]
b=1
h=0
d=t[0]
for i in range(n):
  if(h<=0 and t[i]-d<=k):
    h+=1
  else:
    b+=1
    h=0
    d=t[i+1]
print(b)