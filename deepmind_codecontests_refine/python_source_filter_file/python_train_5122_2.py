n, p = map(int, input().split())
for i in range(1, 1000):
    x = n - i * p
    b = bin(x)
    if x <= 0: break
    if b.count('1') <= i: 
        print(i)
        exit()
print(-1)