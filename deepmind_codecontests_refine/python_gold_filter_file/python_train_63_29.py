n,k = map(int,input().split())
l = list(map(int,input().split()))
p = []
for i in range(len(l)):
    if (k%l[i])==0:
        p.append(l[i])
    
r = max(p)
print(int(k/r))