n, m = map(int, input().split())
count = 0
for i in range(n + m):
    if n + m == 1 or n + m == 0:
        break
    else:
        n -= 1
        m -= 1
        count += 1
print("Malvika" if count % 2 == 0 else "Akshat")