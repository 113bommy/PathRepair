n = int(input())
m = int(input())
x, y = m, 1
for i in range(n):
    y *= 2
    if y >= x:
        break
print(x%y)
