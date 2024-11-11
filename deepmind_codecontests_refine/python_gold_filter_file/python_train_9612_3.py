n = int(input())

mod, rev_el = 1000000007, 250000002
b = ((pow(3, n, mod) - pow(-1, n, mod)) * rev_el) % mod
c = ((pow(3, n - 1, mod) - pow(-1, n - 1, mod)) * rev_el) % mod
a = (3 * c) % mod
print(a)
