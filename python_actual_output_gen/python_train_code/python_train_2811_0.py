n = int(input())
x = list(map(int, input().split()))
z=x.copy()
z2=z.copy()
m=x[-1]
for i in range(n-1,0,-1):
    m=min(x[i],m)
    z[i-1]=m
m=x[0]
for i in range(1,n):
    m=max(m,x[i-1])
    z2[i]=m
y=input()
f="YES"
for i in range(n-1):
    if z[i]<z2[i] and y[i]=="0":
        f="NO"
print(f)