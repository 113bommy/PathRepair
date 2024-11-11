n=int(input())
l=[int(y) for y in input().split()]
i=0
ans=0
l.sort()
print(l)
j=0
for i in range(n):
    while j<n and l[j] -l[i] <=5:
        j+=1
        ans=max(ans,j-i)
print(ans)