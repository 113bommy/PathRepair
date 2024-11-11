n = int(input())

days = map(int, input().split())
limit = sum(days) / n
current = 0

for index, day in enumerate(days):
    current += day

    if current >= limit:
        print(index + 1)
        break
