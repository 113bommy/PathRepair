a,b,k=map(int,input().split())
c=100,d=0
while d<k:
  if a%c==0 and b%c==0:
    d+=1
  c-=1
print(c+1)
