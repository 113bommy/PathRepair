m=input()
m=m.split(' ')
n=int(m[0])
k=int(m[2])
m=int(m[1])
count=0
arr=list()
for i in range(0,m+1):
    a=int(input())
    arr.append(a)
for i in range(0,m):
    num=arr[i]&arr[m]
    num1=arr[i]|arr[m]
    num1=bin(num1).count('0')
    num=bin(num)
    size1=len(bin(arr[i]))
    size2=len(bin(arr[m]))
    if(size1>size2):
        size=size1-2-num1
    else:
        size=size2-2-num1
    num=size-num.count('1')
    if(num<=k):
        count=count+1
print(count)