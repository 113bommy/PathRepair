n = int(input())
def fact(n):
    return 1 if n == 0 else (n * fact(n - 1))

def c(n, k):
    return fact(n) // (fact(k) * (fact(n - k)))

print(c(n, 5) * fact(5))
