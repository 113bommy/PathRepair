n, m, a = map(int, input().split())
if n < 1 or n > 10**9 or m < 1 or m > 10**9 or a < 1 or a > 10**9 :
    print("Error")
a2 = a
i = 1
i2 = 1
if m % a  ==  0:
    i = m / a
else: i = (m // a) + 1
if n  %  a2  ==  0:
    i2 = n / a2
else: i2 = ( n // a2) + 1

i2 = i2 * i
print(i2)
