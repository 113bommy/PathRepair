n = int(input())
k = (int(input()))
a = [(1<<x)+k*(n-x) for x in range(1,n)]
print(min(a))
