p, y = map(int, input().split())
for i in range(y - 1, p, -1):
    if all(i % j for j in range(2, min(int(i ** .5), p + 1))):
        print(i)
        exit()
print(-1)