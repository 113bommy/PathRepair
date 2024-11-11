n = int(input())
c = 1
for i in range(2, n+1):
    if n % i == 0:
        c += 1

print(c)

