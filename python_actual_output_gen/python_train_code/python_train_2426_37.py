n,m=map(int,input().split())

a=max(n,m)
b=[]
for i in range(a):
    for j in range(a):
        if ((i**2)+j==n) and (i+(j**2)==m):
            b.append([i,j])
        else:
            continue

print(len(b))