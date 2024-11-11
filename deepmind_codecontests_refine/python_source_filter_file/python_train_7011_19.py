num1,num2=input().split()
n=int(num1)
m=int(num2)
count=0
for i in range(0,n):
    for j in range(0,m):
        if(((i*i)+j is n) and (i+(j*j) is m)):
            count=count+1
print(count)
