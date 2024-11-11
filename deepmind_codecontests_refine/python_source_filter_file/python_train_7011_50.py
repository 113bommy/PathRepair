n,m=map(int,input().split(" "))
s=0
for i in range(max(n,m)):
    for j in range(min(n,m)):
        if i**2+j==n and j**2+i==m:
            s+=1
print(s)