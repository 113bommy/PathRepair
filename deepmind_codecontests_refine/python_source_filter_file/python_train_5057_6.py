import math
n, k = list(map(int, input().split()))
a = [1]
for i in range(2,int(math.sqrt(n)) + 1):
    if n % i == 0:
        if n // i != i:
            a.append(n // i)
        a.append(i)
a = sorted(a)
if len(a) >= k:
    print(a[k - 1])
else:
    print(-1)




