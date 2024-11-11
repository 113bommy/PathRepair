n = input()
b = input().split()
a = []
for i in b:
    a.append(int(i))
a.sort()
x = 1
y = 0
for i in range(int(n)):
    if x <= a[i]:
        y += 1
    x += 1
print(y)
