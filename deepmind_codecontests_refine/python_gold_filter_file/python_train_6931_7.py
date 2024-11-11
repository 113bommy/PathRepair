import math
n=int(input())
k=int(math.sqrt(n))
k+=1
p=[1]*(n+2)
a=[1]*(n+2)
for i in range(2,k+1):
    if p[i]==1:
        a[i]=1
        for j in range(i*i,n+2,i):
            if p[j]==1:
                p[j]=0
                a[j]=2
if n<3:
    print(1)
else:
    print(2)
for i in range(2,n+2):
    print(a[i],end=" ")
print()