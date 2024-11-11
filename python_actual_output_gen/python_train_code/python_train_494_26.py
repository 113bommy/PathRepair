n,m=map(int,input().split())
l=[int(i) for i in input().split()]
ans=[]
for i in range(n):
    ans.append((l[i],i+1))
ans.sort()
i=0
c=0
sum=0
z=[]
while i<n and sum+ans[i][0]<m:
   sum+=ans[i][0]
   z.append(ans[i][1])
   i+=1 
   c+=1 
print(c)
if c:
    print(*z)