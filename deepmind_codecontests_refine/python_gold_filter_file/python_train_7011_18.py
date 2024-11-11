n,m = map(int,input().split())
cnt = 0
for i in range(1001):
    for j in range(1001):
        if i**2+j==n and i+j**2==m:
            cnt+=1
print(cnt)