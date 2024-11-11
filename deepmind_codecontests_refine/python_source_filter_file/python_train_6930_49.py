n=int(input())
if n%2!=0:
    print(3)
else:
    b=0
    for i in range(1,1001):
        temp=n*i+1
        for j in range(2,n):
            if temp%j==0:
                print(i)
                b=1
                break
        if b==1:
            break
