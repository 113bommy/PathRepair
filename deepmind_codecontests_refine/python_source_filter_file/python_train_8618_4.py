n, k = map(int, input().split())
a = list(map(int, input().split()))
print(len([i for i in a if i > k]))