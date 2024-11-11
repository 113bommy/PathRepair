n=int(input())
a=list(map(int,input().split(" ")))
print(int((sum(a)**2-sum([i**2 for i in a]))/2)%(10**9+7))