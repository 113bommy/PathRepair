n, m, a = map(int, input().split())

if n%a != 0:
    side_n = (n // a) + 1
else:
    side_n = n / a

if m%a != 0:
    side_m = (m // a) + 1
else:
    side_m = m / a

print(side_m * side_n)