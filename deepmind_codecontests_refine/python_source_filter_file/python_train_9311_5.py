n=int(input())
l=list(map(int,input().split()))+[-99**9]
t=1
p=[]
for i in range(1,n+1):
    if l[i] > l[i-1]:
        t+=1
    else:
        p.append((t,i-1))
        t=1
best=1

for i in range(len(p)-1):
    uz=p[i][0]
    end=p[i][1]
    uz2=p[i+1][0]
    end2=p[i+1][1]
    if uz == 1 or uz2 == 1:
        best=max(best,uz2+1,uz+1)
    else:
        k1=end
        k2=end2-uz2+1
        el1= l[k2]-1
        el2=l[k1]+1
        if el1 > l[k1-1] or el2 < l[k2+1]:
            best=max(best,uz2+uz,uz2+1,uz+1)
        else:
            best=max(best,uz2+1,uz+1)
print(best)
