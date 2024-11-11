n,m,a,b=map(int,input().split())
l=[]
for i in range(n):
    for j in range(n):
        if(i+j*m==n):
            l.append(a*i+b*j)
print(min(l))