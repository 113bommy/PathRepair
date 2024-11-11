n = int(input())
price= list(map(int,input().split()))
price=sorted(price)
result=[0]*n
if n % 2==0:
    k=0
    for j in range(1,n,2):
        result[j]=(price[k])
        k+=1
    for j in range(0,n-1,2):
        result[j]=(price[k])
        k+=1

    print(n//2 -1)
    for value in result:
        print(value,end=' ')
if n % 2!=0:
    k=0
    for j in range(1,n-1,2):
        result[j]=(price[k])
        k+=1
    for j in range(0,n,2):
        result[j]=(price[k])
        k+=1

    print((n-1)//2)
    for value in result:
        print(value,end=' ')
    