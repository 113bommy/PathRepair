n,m=map(int,input().split())
l=list(map(int,input().strip().split()))
l.insert(0,1)
r=0
z=[]
q=[]
for i in l[1:]:
    if i>l[r]:
        a=i-l[r]
        z.append(a)
    elif i<l[r]:
        b=(4-l[r])+(i-0)
        q.append(b)
    r+=1
print(sum(z)+sum(q))