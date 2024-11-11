def rat(b,x,y):print(b[y]-b[x-1])
a=int(input())
b=[0]+list(map(int,input().split()))
c=sorted(b.copy())
for i in range(1,a+1):b[i]+=b[i-1];c[i]+=c[i-1]
for _ in " "*int(input()):
    x,y,z=map(int,input().split())
    if x==1:rat(b,y,z)
    else:rat(c,x,y)
