n,m=map(int,input().split())
a=[]
for i in range (1001):
    for j in range(1001):
        if i*i+j==n and i+j*j==m:
            a.append(i)
            a.append(j)
print(len(a)/2)