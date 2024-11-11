n = int(input())
c = 1
for i in range(2, n):
    if n % i == 0:
        c += 1

print(c)

