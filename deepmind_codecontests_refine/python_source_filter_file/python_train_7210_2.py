num_pages = int(input())
pages_per_day = [0]
pages_per_day.extend(list(map(int, input().split())))
pages_per_week = sum(pages_per_day)
remaining_pages = num_pages%pages_per_week
if remaining_pages == 0:
    remaining_pages -= pages_per_week
for day in range(1,8):
    remaining_pages -= pages_per_day[day]
    if remaining_pages <= 0:
        print(day)
        break
