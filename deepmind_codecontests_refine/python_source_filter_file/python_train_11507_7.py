def fact(x):
    if x == 0:
        return 1
    else:
        return x * fact(x - 1)

n = int(input())
print(fact(n) / (fact(5) * fact(n - 5)) + fact(n) / (fact(6) * fact(n - 6)) + fact(n) / (fact(7) * fact(n - 7)))