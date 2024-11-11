x,y,l,r=map(int,input().split())
p=set()
p.add(l-1)
p.add(r+1)
for i in range(0,65):
    s=x**i
    if x>r:
        break
    for j in range(0,65):
        t=y**j
        if s+t>r:break
        elif s+t>=l:
            p.add(s+t)

p=sorted(list(p))
#print(p)
ans=0
for i in range(1,len(p)):
    ans=max(ans,p[i]-p[i-1]-1)
print (ans)