n=int(input())
ans=[]
if n%2==0:
    for i in range(1,n):
        for j in range(i+1,n+1):
            if i+j!=n+1:
                ans.appned([i,j])
else:
    for i in range(1,n):
        for j in range(i+1,n+1):
            if i+j!=n:
                ans.appned([i,j])
print(len(ans))
for i,j in ans:
    print(i,j)
