n=int(input())
array=[]
for i in range(0,n):
    x=int(input())
    array.append(x)
array.sort()
sum=0
for i in range(0,n):
    sum=sum+array[i]*array[n-1-i]
print(sum%10007)

