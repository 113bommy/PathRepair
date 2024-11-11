n=int(input())
if n==1 or n==2:
    print(1)
else:
    num=n//3
    if n%3:
        print(num+1)
    else:
        print(num)

