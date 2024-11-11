n=int(input())
sum=0
for l in range(1,n):
    if (n-l)%l==0:
        sum+=1

print(sum)