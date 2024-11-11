n,k=map(int,input().split())
m=-100000
for i in range(n):
    f,t=map(int,input().split())
    if(t<k):
        m=max(m,f)
    else:
        m=max(m,f-(t-k))
print(m)