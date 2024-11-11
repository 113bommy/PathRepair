a,b=map(int,input().split())
k,m=map(int,input().split())
x=[int(q) for q in input().split()]
y=[int(e) for e in input().split()]

t=x[k-1]
index=0
for i in range(len(y)):
    if y[i]>t:
        index=i
        break
r= len(y) - index
if index==0:
    print("NO")
else:
    if r>=m:
        print("YES")
    if r<m:
        print("NO")