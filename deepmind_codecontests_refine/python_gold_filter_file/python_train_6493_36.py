n=int(input())
sum=0
for i in range(2,n):
    sum=sum+i*(n-i)

sum=sum+2*n-1
print(sum)