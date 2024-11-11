a1 = int(input())
a2 = int(input())
k1 = int(input())
k2 = int(input())
n = int(input())
mx = 0
mn = 0
s = (k1 - 1)*a1 + (k2 - 1)*a2
if (s < n) and (s > 0):
    mn = n - s
if k1 < k2:
    if n <= (a1*k1):
        mx = n // k1
    else:
        z = n - (a1*k1)
        mx = a1 + (z // k2)
else:
    if n <= (a2*k2):
        mx = n // k2
    else:
        z = n - (a2*k2)
        mx = a2 + (z // k1)
print(mn, mx)