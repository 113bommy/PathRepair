n,t=map(int, input().split())
x=[]
y=[]
m=[]
for i in range(n):
    a,b=map(int, input().split())
    x.append(a)
    y.append(b)
    m.append([a,b])
x.sort()
y.sort()
ans=float('inf')
for i in range(n-1):
    for j in range(i,n):
        if i>=j:continue
        for k in range(n-1):
            for l in range(k,n):
                if k>=l:continue
                count=0
                for a,b in m:
                    if x[i]<=a<=x[j] and y[k]<=b<=y[l]:
                        count+=1
                if count>=t:
                    ans=min(ans,(x[j]-x[i])*(y[l]-y[k]))
print(ans)
    
