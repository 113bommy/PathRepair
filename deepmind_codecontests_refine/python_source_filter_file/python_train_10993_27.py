from math import floor
a = ["sheldon", "leonard", "penny", "Rajesh", "howard"]
n = int(input())
n = n-1
while n >= 5:
    n = n - 5
    n = floor(n/2)

print(a[n])
