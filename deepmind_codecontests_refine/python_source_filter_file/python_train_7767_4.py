n = int(input())
l = list(map(int, input().split()))
if n == 1: 
    print(l[0], 0)
    exit()
l.reverse()
y = l[0]
x = l[1]
for i in range(2, n):
    if x > y:
        y += l[i]
    else:
        x += l[i]
if x > y: x, y = y, x
print(x, y)