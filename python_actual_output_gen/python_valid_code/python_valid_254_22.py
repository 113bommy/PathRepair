n,r = map(int,input().split())
if n==1 and r==1:
    print(1)
else:
    for i in range(1,n):
        if (n*i)%10==0 or (n*i)%10==r:
            print(i)
            break