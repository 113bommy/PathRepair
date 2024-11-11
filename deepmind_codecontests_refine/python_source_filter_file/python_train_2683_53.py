N = int(input())
a = 10**N - 8**N - 2*(9**N)
b = a % (10**9  + 7)
print(b)
