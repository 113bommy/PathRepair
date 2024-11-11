n=int(input())
ans=0
x=[]
y=[]
for i in range(n):
    a,b=map(int,input().split())
    x.append({a})
    y.append({b})
for i in range(n-1):
    for j in range(i+1,n):
        if x[i]&x[j] or y[i]&y[j]:
            x[i]|=x[j]
            y[i]|=y[j]
            ans+=1
            break
print(n-ans+1)