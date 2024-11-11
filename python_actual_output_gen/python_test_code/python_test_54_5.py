n,x0=map(int,input().split())
pos=set()
a,b=map(int,input().split())
a1=min(a,b)
a2=max(a,b)
for i in range(a1,a2+1):
    pos.add(i)
for i in range(n-1):
    a,b=map(int,input().split())
    a1=min(a,b)
    a2=max(a,b)
    L=[]
    for each in pos:
        if each not in range(a1,a2+1):
            L.append(each)
    for each in L:
        pos.remove(each)
if len(pos)==0:
    print("-1")
else:
    ans=x0
    for each in pos:
        ans=min(ans,abs(x0-each))
    print(ans)
