n, m = map(int,input().split())
a = 0
b = 0
count = 0
while b**2 < m:

    a2 = m - b ** 2
    b1 = n - a2 ** 2
    if b ==  b1:
        a = a2
        # print ( a, b)
        count += 1
    b += 1
print(count)

