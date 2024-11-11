def fact(a):
    if a == 1:
        return 1
    else:
        return fact(a - 1) * a
n = int(input())
print(fact(n) // fact(n // 2) // (n // 2) * (fact(n // 2) // (n // 2)) // 2)