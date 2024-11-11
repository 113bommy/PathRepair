n,m,k=map(int,input().split())
p=list(map(int,input().split()))
t=0
for i in range(m):
    a=list(map(int,input().split()))
    for x in a:
        ind=p.index(x)
        t+=(ind+1)
        p.pop(ind)
        p.insert(0,x)
print(t)


        
