n1,n=map(int,input().split())
i=1
while(i):
    if ((n1*i)-n)%10==0 or (n1*n)%10==0:
        print(i)
        break
    i+=1