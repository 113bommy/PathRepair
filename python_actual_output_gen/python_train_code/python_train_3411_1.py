r = int(input())
d = int(input())
e = 5 * int(input())
rem = r % d
a = r % e
for i in range(a + 1):
    b = r - i * e
    if b < 0:
        break
    rem = min(rem, b % d)
print(rem)