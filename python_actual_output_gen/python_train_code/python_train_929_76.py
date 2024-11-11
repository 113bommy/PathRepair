n,h =  map(int, input().split())
a = list(map(int, input().split()))
b = sum([1 if i>=h else 2 for i in a])
print(b)