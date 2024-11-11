n,m=map(int,input().split())
num=(n/2)*m
if n%2==1:
    num+=(m/2)
print(num)