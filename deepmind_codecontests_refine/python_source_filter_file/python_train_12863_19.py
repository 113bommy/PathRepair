n,r = map(int,input().split())
for i in range(1,n):
    if (n*i)%10==0 or (n*i)%10==r:
        print(i)
        break