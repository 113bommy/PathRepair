n=int(input())
d={}
for i in range(n-1):
    a,b=map(int,input().split())
    d[a],d[b]=d.get(a,0)+1,d.get(b,0)+1
root=[]
lev=[]
for a, b in d.items():
    if b>2: root.append(a)
    if b==1: lev.append(a)
if len(root)>2:
    print("No")
else:
    if len(root)==0:
        print("Yes")
        print("1")
        print(*lev)
    else:
        print("Yes")
        print(d[root[0]])
        for a in lev:
            print(root[0],a)
            
        
