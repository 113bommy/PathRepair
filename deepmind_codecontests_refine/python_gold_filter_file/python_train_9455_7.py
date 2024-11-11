n = int(input())
x = list(map(int, input().split()))
a = max(x)
b = a
for i in x:
    if abs(a/2 - i) <= abs(a/2 - b):
        b = i
print(a, b)