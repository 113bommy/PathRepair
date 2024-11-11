num1,num2=input().split()
n=int(num1)
m=int(num2)
count=0
for i in range(0,n+1):
    for j in range(0,m+1):
        if(((i*i)+j == n) and (i+(j*j) == m)):
            count=count+1
print(count)
