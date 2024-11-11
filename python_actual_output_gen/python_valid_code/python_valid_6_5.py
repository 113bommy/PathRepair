n,k=map(int,input().split())

l=[]
for i in range(n):
    l.append(list(map(int,input().split())))
    
l.sort()

i=n-1
ans=0
while k>0:
    k=k-l[i][1]
    ans=l[i][0]
    i=i-1
print(ans)