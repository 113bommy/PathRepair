n = 50000
c = [1 for i in range(n)]
c[0] = 0
i = 2
while i**2 <= n:
    j = i*2
    while j <= n:
        c[j - 1] = 0
        j += i
    i += 1

while True:
    try:
        n = int(input())
        i, a, b = 0, 0, 0
        while a == 0 or b == 0:
            i += 1
            if n - i - 1 >= 0 and a == 0 and c[n - i - 1] == 1:
                a = n - i
            if n + i - 1 < 50000 and b == 0 and c[n + i - 1] == 1:
                b = n + i
        print(a,b)
    except:
        break

