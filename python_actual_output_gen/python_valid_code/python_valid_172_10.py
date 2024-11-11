n,m=map(int,input().split())
h=0
v=1
l=[]
for i in range(0,n):
    a=list(input())
    a=[int(u) for u in a]
    l.append(a[0])
    if len(list(set(a)))==1:
        h=h+1
for x,y in zip(l,l[1:]):
    if x==y:
        v=0
        break
if v==1 and h==m:
    print("YES")
else:
    print("NO")
        