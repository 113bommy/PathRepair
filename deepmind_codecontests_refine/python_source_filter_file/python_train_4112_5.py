s = input()
n = int(s)

r = 0
k = 10 ** 0
for i in range(len(s)):
    r += (10 ** i - k) * i
    k = 10 ** i
r += (n - (k - 1)) * (i + 1)
