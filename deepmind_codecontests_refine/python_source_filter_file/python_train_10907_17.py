x,k,d=map(int,input().split())
cur=abs(x)
count=min(cur//d,k)
cur-=d*count
s=k-count
if s%2==1:
  cur-=-d
print(abs(cur))
