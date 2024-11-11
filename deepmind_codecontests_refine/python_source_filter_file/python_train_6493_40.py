n=int(input())
asum=0
for i in range(2,n):
    asum=asum+i*(n-2)
asum=asum+2*n-1
print(asum)
