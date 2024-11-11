n = (int(input()))
r = n % 10
if r == 0:
    print(n)
if 1 <= r <= 5:
    print(n-r)
else:
    print(n+10-r)

