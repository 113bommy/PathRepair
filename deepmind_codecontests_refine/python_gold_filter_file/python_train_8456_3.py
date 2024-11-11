def get_answer(n):
    k = 2
    while 2**k - 1 <= n:
        if n % (2**k - 1) == 0:
            return n // (2**k - 1)
        k += 1
 
t = int(input())
for _ in range(t):
    n = int(input())
    print(get_answer(n))