count = 0
for _ in range(int(input())):
    a, b = map(int, input().split())
    if a-b >= 2:
        count += 1
print(count)