n, a = int(input()) + 1, sum(list(map(int, input().split())))
counter = 0
for i in range(1, 6):
    if (a + i) % n:
        counter += 1
print(counter)