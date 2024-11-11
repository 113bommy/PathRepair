import sys
for _ in range(int(input())):
    n,m =map(int,input().split())
    sum=0
    d=n//m
    for i in range(1,10):
        sum+=(m*i)%10
    i=d%10
    d=d-i
    sum=sum*d/10
    for j in range(1,i+1):
        sum+=(m*j)%10
    print(sum)
