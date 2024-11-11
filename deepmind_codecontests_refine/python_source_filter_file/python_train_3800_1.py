n, x = map(int, input().split())
count = 0
i = 1
a = []
R = 0
if n**2 >= x:
    while i not in a and i<=n:
        if x % i ==0:
            a.append(i)
            if i <= n and x // i <= n:
                if x % i == i:
                    R += 1
                else:
                    R += 2
                    a.append(x // i)
        i += 1
print(R)

