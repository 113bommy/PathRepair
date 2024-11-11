n,k=map(int,input().split())
x=[0]*n;y=[0]*n
for i in range(n):x[i],y[i]=map(int,input().split())

ans=1e20
for i in range(n):
    for j in range(i+1, n):
        for a in range(n):
            for b in range(a+1, n):
                cnt=0
                x1=min(x[i],x[j])
                x2=max(x[i],x[j])
                y1=min(y[a],y[b])
                y2=max(y[a],y[b])
                for c in range(n):
                    if x1<=x[c]<=x2 and y1<=y[c]<=y2: cnt+=1
                if cnt>=k:
                    ans=min(ans,(x2-x1)*(y2-y1))
print(ans)