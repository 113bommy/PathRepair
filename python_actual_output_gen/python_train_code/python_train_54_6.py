n,c=list(map(int,input().split()))
p=list(map(int,input().split()))
m=0
for i in range(n-1):
    if p[i]>p[i+1]:
        m=max(m,p[i]-p[i+1])
print(m-c)