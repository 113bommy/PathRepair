h,w,m=map(int,input().split())
h_=[0]*(h+1)
w_=[0]*(w+1)
plot=[]
for _ in range(m):
    x,y=map(int,input().split())
    h_[x]+=1
    w_[y]+=1
    plot.append((x,y))
x=max(h_)
y=max(w_)
a=[i for i,v in enumerate(h_) if v==x]
b=[j for j,q in enumerate(w_) if q==y]
ans=x+y-1
c=False
for i in a:
    for j in b:
        if (i,j) not in plot:
          c=True
          break
    if c:
      break
if c:
  print(ans+1)
else:
  print(ans)
          
        
        
