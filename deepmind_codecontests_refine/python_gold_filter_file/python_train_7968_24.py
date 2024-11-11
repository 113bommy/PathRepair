n = int(input())
a = 0
if n == 1 or n == 2: print(-1)
elif n % 2:
    a = (n * n) // 2
    print(a, a + 1)
else: 
    t = n // 2
    a = (t * t) - 1
    print(a, a + 2)