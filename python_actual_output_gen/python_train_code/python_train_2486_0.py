n=int(input())
l=[[0,0]]
for i in range(n):
    l.append(list(map(int,input().split(" "))))
s=0
change=True
for i in range(n):
    if(change):
        s+=max(min(l[i+1])-max(l[i])+1,0)
    else:
        s+=max(min(l[i+1])-max(l[i]),0)
    if(l[i]==(l[i+1])):
        change=False
    else:
        change=True
        
print(s)