a,b=map(int,input().split())
z=0
r=[0]+list(map(int,input().split()))
for i in range(1,a+1):
    j=0
    for j in range(i,a+1):
        if r[j]-r[i]>b:z=max(z,j-i);break
    else:z=max(z,j-i+1)
print(a-z)