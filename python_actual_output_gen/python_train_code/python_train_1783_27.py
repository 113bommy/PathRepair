p=input()
n,m=map(int,p.split())
q=input()
q=list(map(int,q.split()))
c=0
d=0
for i in q:
    if i<0 and c<m:
        d+=-1*i
        c+=1
    if c==m:
        break
print(d)