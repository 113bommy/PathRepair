n=int(input())
if n==3:
    print(1,1,1)
    exit()
if n==4:
    print(2,1,1)
    exit()
if n==5:
    print(2,2,1)
    exit()
if n==6:
    print(2,2,2)
    exit()
if (n-2)%3==0:
    print(n-1,2,1)
else:
    print(n-2,1,1)
