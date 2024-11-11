n = int(input())

print('0 0')
n-=1
k = n // 2
p = n - k
x = -2
while k > 0:
    if x != 0:
        print(x, 0)
        k -= 1
    x += 1
y = -2
while p > 0:
    if y != 0:
        print(0, y)
        p -= 1
    y += 1