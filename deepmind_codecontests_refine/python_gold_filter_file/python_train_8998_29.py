n = int(input())
answ = 1 + 2 ** (n % 4) + 3 ** (n % 4) + 4 ** (n % 4)
print(answ % 5)
