n, x = map(int, input().split())
count = 0
i = 1
R = 0
while i*i <= x:
    if x % i ==0 and i <= n and x // i <= n:
        print(i, x // i)
        if i != x // i:
            R += 2
        else:
            R += 1
    i += 1
# print(R)

