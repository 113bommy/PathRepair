count_info = list(map(int, input().split(' ')))

city_crime = list(map(int, input().split(' ')))
value = 0
for i in range(0, count_info[1]-1):
    
    if city_crime[i] == 1:
        if (count_info[1]-1)*2-i > count_info[0]-1:
            value += 1
        elif city_crime[(count_info[1]-1)*2-i] == city_crime[i]:
            value +=2


if count_info[0] > (count_info[1]-1)*2+1:
    for i in range((count_info[1]-1)*2+1, count_info[0]):
        if city_crime[i] == 1:
            value += 1


if city_crime[(count_info[1]-1)] == 1:
    print(value+1)
else:
    print(value)