n=int(input())
ans=[0]+[n for i in range(n)]
e=[[i+1,i-1] if i<n else [i-1] for i in range(0,n+1)]
e[0],ans[1]=[],0
for i,x in enumerate(map(int,input().split())):
    if i+1!=x: e[i+1]+=[x]
ch=[(0,1)]
while ch:
    l,nom=ch.pop()
    for x in e[nom]:
        if l+1<ans[x]: ans[x]=l+1; ch.append((l+1,x))
print(*ans[2:])    
