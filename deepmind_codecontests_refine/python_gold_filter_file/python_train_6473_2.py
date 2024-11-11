n=int(input())
m=sum(int(x)%2 for x in input().split())
print(min(m,n-m))