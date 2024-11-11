n = int(input())
days = map(int, input().split())

rests, yesterday = 0, 0
for today in days:
    if today == 0 or yesterday == today:
        rests += 1
        yesterday = 0
    elif today == 1 or today == 2:
        yesterday = today
    elif yesterday > 3 and today == 3:
        yesterday = 3 - yesterday

print(rests)
