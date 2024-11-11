num = int(input())
a = [0]*num
b=[0]*num

sum1=sum2=0
for i in range(0,num):
    a[i],b[i]= tuple(int(i) for i in input().strip().split(" "))
sum1 = sum(a)
sum2 = sum(b)
mx = abs(sum1-sum2)
index = 0
for i in range(0,num):
    sum1 = sum1-a[i]+b[i]
    sum2 = sum2-b[i]+a[i]
    if(mx< abs(sum1-sum2)):
        mx = abs(sum1-sum2)
        index = i+1
    sum1 = sum1-b[i]+a[i]
    sum2 = sum2 - a[i] + b[i]
print(mx)