n=int(input())
sum=-1
for i in range(1,n+1):
    if n%i==0:
        sum+=1
print(sum)