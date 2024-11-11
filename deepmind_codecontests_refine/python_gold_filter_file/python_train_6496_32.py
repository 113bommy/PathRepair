n,m=list(map(int, input().split()))

numbers=list(map(int, input().split()))

last=1
sum=0

for i in range (m):
    if (numbers[i]>last):
        sum=sum+numbers[i]-last
    elif (numbers[i]<last):
        sum=sum+(n-last+numbers[i])
    last=numbers[i]

print(sum)