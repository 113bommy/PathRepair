a, b = map(int, input().split())
hours = 240
count = 0
i = 1
while b <= hours - count + 5 and i <= a:
    count = 5 * i
    i += 1
    hours -= count
print(count // 5)