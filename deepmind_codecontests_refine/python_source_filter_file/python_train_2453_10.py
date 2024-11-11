d = {'monday': 1, 'tuesday': 2, 'wednesday': 3, 'thursday': 4, 'friday': 5, 'saturday': 6, 'sunday': 7}

day1=str(input())
day2=str(input())


if day1 == day2 or (d[day1] + 2) % 7 == d[day2] or (d[day1] + 3) % 7 == d[day2]:
    print("YES")
else:
    print("NO")