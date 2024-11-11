n = int(input())
mod = (10 ** 9) + 7
x = (1 / 4) * ((3 * ((-1) ** n)) + pow(3, n, mod * 4))
print(int(x))