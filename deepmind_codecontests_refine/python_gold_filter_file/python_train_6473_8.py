n=int(input())
ans=sum(int(x)%2 for x in input().split())
print(min(ans,n-ans))