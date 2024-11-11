n,k=map(int,input().split())
v=[]
for i in range(2,n+1):
    if all(i%j==0 for j in v):
        v.append(i)
c=0
for i in range(len(v)-1):
    if v[i]+v[i+1]+1 in v:
        c+=1
if c>=k:
    print("YES")
else:
    print("NO")