l=set()
n,x,y=map(int,input().split())
for i in range(n):
    a,b=map(int,input().split())
    if a-x==0:
        l.add(10**9+7)
    else:
        l.add((b-y)/(a-x))

print(len(l))
