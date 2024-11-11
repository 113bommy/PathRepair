n,m = input().split()
n = int(n)
m = int(m)
if m == 0:
    print (n)
elif m >= n/2:
    print(n-m)
else:
    print(m)
    