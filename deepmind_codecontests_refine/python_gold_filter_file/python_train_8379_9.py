n = int(input(''))

percent = 10**9 + 7
total = 3**(3*n)
bad   = 7**n
print ((total - bad) % percent)
