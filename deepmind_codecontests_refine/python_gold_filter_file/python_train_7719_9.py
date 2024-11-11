n,m = input().split()
n = int(n)
m = int(m)
if m <= 1:
    print(1)
elif m >= n/2:
    print(n-m)
else:
    print(m)
    