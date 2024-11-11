S = int(input())

n = 10 ** 9
Y = (n - (S % n)) % n
X = (S + Y) // n

print("0 0 1 {} {} {}".format(n, X, Y))