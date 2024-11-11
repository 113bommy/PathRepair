
n=int(input())
l=list(map(int,input().split()))
b=max(l)-min(l)+1
print(n-b)