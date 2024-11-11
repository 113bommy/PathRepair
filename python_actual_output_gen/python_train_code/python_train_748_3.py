n=int(input())
a=list(map(int,input().split()))
b=sum([i**2 for i in a])
print((sum(a)**2-b)%(10**9+7)//2)