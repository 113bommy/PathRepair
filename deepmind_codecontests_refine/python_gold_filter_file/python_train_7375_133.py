n=int(input())
a=list(map(int,input().split()))
a.sort()
ans=0
b=a[n:-1:2]
print(sum(b))