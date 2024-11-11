n,m=map(int,input().split())

a=max(n,m)
b=[]
for i in range(a+1):
    for j in range(a+1):
        if ((i**2)+j==n) and (i+(j**2)==m):
            b.append([i,j])
        else:
            continue

print(len(b))