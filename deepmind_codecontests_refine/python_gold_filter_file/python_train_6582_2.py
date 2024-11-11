def C(n,m):
    return f[n]//(f[m]*f[n-m])
n,m,t=map(int,input().split());f=[1];o=0
for i in range(n+m+2):f.append(f[i]*(i+1))
for i in range(4,n+1,1):
    for j in range(1,m+1,1):
        if(i+j!=t):continue
        o+=C(n,i)*C(m,j)
print(o)
