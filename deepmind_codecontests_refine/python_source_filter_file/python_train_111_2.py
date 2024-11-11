n = int(input())
a = list(map(int, input().split()))
x = max(a)
c = 0
y = 0
for i in a:
    c += x - i
    y += i
if y < c:
    print(x)
else:
    z = 0
    while c < y:
        c += n
        z += 1
    print(x + z)