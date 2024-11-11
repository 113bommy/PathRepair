a,b=map(int,input().split())
a=a+1
n=a
k=10
while(True):
    if ((a%k)>b):
        break
    n=a-(a%k)
    k*=10
print(n-1)