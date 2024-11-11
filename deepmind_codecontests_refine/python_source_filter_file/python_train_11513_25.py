import string

n, k  = [int(x) for x in input().split()]

alphabet = string.ascii_lowercase
symbol = alphabet[:k]

if n == k:
    print(symbol)
elif n > k:
    s = symbol * (n // k)
    if len(s) != n:
        s += symbol[0]
    print(s)
else:
    s = symbol[:n]
    print(s)
