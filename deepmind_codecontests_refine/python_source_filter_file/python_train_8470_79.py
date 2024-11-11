year = int(input()) + 1

while True:
    if year < 1000 or year > 9000: 
        break
    li = list()
    temp = year
    while temp > 0: 
        li.append(temp % 10)
        temp = temp // 10
    if len(li) == len(set(li)):
        print(year)
        break
    year += 1