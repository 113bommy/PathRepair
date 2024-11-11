n,m=map(int,input().split())
l=[0]*5
d=[0]*5
for i in range(1,n+1):
    x=i%5
    l[x]+=1
for j in range(1,m+1):
    x=j%5
    d[x]+=1
s=l[0]*d[0]
for i in range(1,5):
    s=s+l[i]*d[5-i]
print(s)