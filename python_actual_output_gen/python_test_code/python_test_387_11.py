n = int(input())

A = 1234567
B = 123456
C = 1234

for a in range(n // A):
    for b in range(n // B):
        c = n - a * A - b * B
        if c > 0 and c % C == 0:
            exit(print("YES"))
print("NO")
