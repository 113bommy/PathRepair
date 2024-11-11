def fact(n):
    if n == 1:
        return 1
    return n*fact(n-1)

n = int(input())
print(int(fact(n-1)/(n//2)))
