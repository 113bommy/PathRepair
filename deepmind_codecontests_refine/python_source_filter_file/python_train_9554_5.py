h,w,m=map(int,input().split())
g=[]
e1=[0]*h
e2=[0]*w
for c in range(m):
    a,b=map(int,input().split())
    g.append([a-1,b-1])
    e1[a-1]+=1
    e2[b-1]+=1
p1=max(e1)
p2=max(e2)
x=[1 if e1[c]==p1 else 0 for c in range(h)]
y=[1 if e2[c]==p2 else 0 for c in range(w)]
r=sum(x)*sum(y)
for i in g:
    if x[i[0]]==1 and y[i[1]]==1:
        r-=1
if r==0:
    print(p+q-1)
else:
    print(p+q)