n,m = map(int, input().split())
a = sum(map(int, input().split()))
print(n-a if n>n-a else -1)