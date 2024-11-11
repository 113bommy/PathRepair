import os
n,k=map(int,input().split())
if(k==2):
    if(n>=5):
        print(n-1)
        for i in range(1,n):
            print(i,i+1)
        os._exit(0)
elif(k==3):
    if(n>=4):
        print(2*(n-3)+1)
        print(1,2)
        for i in range(3,n):
            print(i,n)
            print(2,i)
        os._exit(0)
print(-1)
