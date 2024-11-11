yr = int(input())

def distinct(yr):
    ys = str(yr)
    dd = {}
    for i in range(len(ys)):
        if ys[i] not in dd:
            dd[ys[i]] = 1
        else:
            return False
    return True

final = 0
year = yr + 1
while year <= 9000:
    if distinct(year):
        final =  year
        break
    year += 1

print(final)
