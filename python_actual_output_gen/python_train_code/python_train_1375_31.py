n = int(input())
a = []
b = 1
for i in range(n):
    a.append(int(input()))
for i in range(n-2):
    if a[i] != a[i+1]:
        b += 1
print(b)
