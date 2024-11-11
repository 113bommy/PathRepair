n=int(input())
l1=list(map(int,input().split()))
l1.sort()
sum1=0;
for i in range(n):
    sum1=sum1+l1[i]
m=int(input())
l2=list(map(int,input().split()))
for i in range(m):
    x=l2[i]
    y=sum1
    y=y-l1[n-x];
    print(y)
