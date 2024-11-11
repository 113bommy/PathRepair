n,m=map(int,input().split())
count=0
for i in range(max(n,m)):
    for j in range(max(n,m)):
        if i**2+j==n and i+j**2==m:
            count+=1
print(count)