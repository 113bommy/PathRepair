n = int(input())

notans = 7
allans = 27

for i in range(n - 1):
    notans *= 7
    notans %= (10**9 + 7)

for i in range(n - 1):
    allans *= 27
    allans %= (10**9 + 7)

print((allans - notans + 10**9 - 7) % (10**9 + 7))