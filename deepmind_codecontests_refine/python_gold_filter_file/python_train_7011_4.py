n,m = input().split()
n = int(n)
m = int(m)
r = max(n,m)
count = 0
for i in range(r+1):
    for j in range(r+1):
        if i**2 + j == n and j**2 + i == m:
            count += 1
print(count)