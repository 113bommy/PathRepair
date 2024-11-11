n = int(input())

A = 1234567
B = 123456
C = 1234

for a in range(n // A + 1):
    for b in range(n // B + 1):
        c = n - a * A - b * B
        if c > 0 and c % C == 0:
            exit(print("YES"))
print("NO")
