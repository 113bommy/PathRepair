n=int(input())
a=[int(i) for i in input().split()]
M=[0]*n
M[0]=sum(a[i]*(-1)**i for i in range(n))
for i in range(1,n):
    M[i]=2*a[i-1]-M[i-1]
print(M)