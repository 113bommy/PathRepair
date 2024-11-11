t = input().split()
n = int(t[0])
m = int(t[1])

count = 0

for a in range(1001):
    for b in range(1001):
        if a**2 + b == n and b**2 + a == m:
            count += 1

print(count)