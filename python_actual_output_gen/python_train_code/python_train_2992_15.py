n,m,k=map(int,input().split())
others=[]
friend=0
for i in range(m):
    others.append(int(input()))
fedor=int(input())
fedor=bin(fedor)
fedor=fedor.lstrip('0b')
fedor=list(fedor)
fedor.reverse()
fedor=fedor+['0']*(n-1-len(fedor))
for i in others:
    differ=0
    i=bin(i)
    i=i.lstrip('0b')
    i=list(i)
    i.reverse()
    i=i+['0']*(n-1-len(i))
    for j in range(n-1):
        if i[j] != fedor[j]:
            differ=differ+1
    if differ<=k:
        friend=friend+1
print(friend)
        
            
