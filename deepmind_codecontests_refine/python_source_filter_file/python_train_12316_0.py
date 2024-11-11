k=int(input())
l=int(input())
m=int(input())
n=int(input())
d=int(input())

if k==1 or l==1 or m==1 or n==1:
    print(d)
else:
    result = 0
    for i in range(d):
        if (i+1)%k==1:
            result +=1
        elif (i+1)%l==1:
            result +=1
        elif (i+1)%m==1:
            result +=1
        elif (i+1)%n==1:
            result +=1
        else:
            pass
    print(result)