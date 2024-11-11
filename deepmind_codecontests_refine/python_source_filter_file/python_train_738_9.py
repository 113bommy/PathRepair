n = int(input())

for i in range(2, n):

    if n % i == 0:
        print(int((n-i) / 2 + 1))
        raise SystemExit

    if i > 10000:
        break

print(1)