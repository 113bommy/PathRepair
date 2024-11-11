M = 10**9 + 7
a = [1] + [0] * 12
p = 1
for c in reversed(input()):
    r = range(0, p * 10, p) if c == '?' else (p * int(c),)
    if c != '?':
      a = [a[(i - p * int(c)) % 13] for i in range(13)]
    else:
      a = [sum(a[(i - j) % 13] for j in range(0, p * 10, p)) % M for i in range(13)] 
    p = p * 10 % 13
print(a[5])
