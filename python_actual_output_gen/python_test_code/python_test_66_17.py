x=int(input())
y=list(input())
p=list(map(int,input().split()))
mi=p[x-1]
for i in range(x-1):
    if y[i]=="R" and y[i+1]=="L":
        mi=min(mi,p[i+1]-p[i])
print(mi//2 if mi!=p[x-1] else -1)
        

