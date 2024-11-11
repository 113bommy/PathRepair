n,k = input().split()
n,k = int(n),int(k)
m = 0

if n % 2 == 0:
        m = int(n/2)
else:
        m = int(n/2) + 1

if k <= m:
        print(2*k - 1)
else:
        print(2 * (k - m))
