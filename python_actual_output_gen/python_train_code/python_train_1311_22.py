m, x = map(int, input().split())
count = 0
if x == 1 or x == m*m:
    count = 1
elif x < m*m:
    for i in range(1, x//2+1):
        if x % i == 0:
            for j in range(1, x//2+1):
                if i * j == x:
                    count += 1

print(count)