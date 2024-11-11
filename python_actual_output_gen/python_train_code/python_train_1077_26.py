n=int(input())
l=list(map(int,input().split()))
s=sum(l)
m=[]
for i in range(1,n-1):
    m.append(abs(-sum(l[:i])*2))
print(min(m))