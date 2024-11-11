import math

m = input()

for i in range(int(m)):
    track = int(input())
    cars = list(map(int, input().split()))
    total_cars = sum(cars)

    temp_track = track
    max_total = 1
    max_elm = 1
    for j in range(len(cars)):
        avg = total_cars/temp_track
        p = math.ceil(avg)
        cars[j] = p

        total_cars -= p
        temp_track -= 1

        if(j == 0):
            max_elm = p
            max_total = 1
        else:
            if(p == max_elm):
                max_total += 1

    temp_track = 0
    for j in range(1, len(cars)):
        if(j <= max_total):
            total_cars = abs(cars[0] - cars[j])*j
            temp_track += total_cars
        else:
            temp_track += total_cars*(track - j)
            break

    print(temp_track)