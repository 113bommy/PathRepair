year = int(input()) + 1
old_year = 0
def HaveNum(x):
    if year.count(x) >= 1:
        return 1
    else:
        return 0

while True:
    lst = list(map(int, list(str(year))))
    old_year = year
    for x in lst:
        if lst.count(x) >= 2:
            year += 1
            continue

    if old_year == year:
        break

print(year)
