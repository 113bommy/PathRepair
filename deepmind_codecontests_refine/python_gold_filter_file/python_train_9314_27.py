n,x,y=map(int,input().split())
s=set()
for i in range(n):
    a,b=map(int,input().split())
    if b-y!=0:
        s.add((a-x)/(b-y))
    else:
        s.add(float("INF"))
print(len(s))
