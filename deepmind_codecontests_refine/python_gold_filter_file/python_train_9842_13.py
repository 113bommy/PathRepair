import math


def find_drinkingwater_bycentemeter(drinking_speed, diameter):
    drinking_speed_bycentemeter = drinking_speed/(math.pi*((diameter/2)**2))
    return drinking_speed_bycentemeter


def find_empty_time():
    diameter, water_hight, drinking_speed, water_growth = map(float,input().split())

    drinking_speed_centemeter = find_drinkingwater_bycentemeter(drinking_speed, diameter)
    if drinking_speed_centemeter == water_growth:
        print("NO")
    else:
        empty_time = water_hight/(drinking_speed_centemeter - water_growth)
        if empty_time < 0:
            print("NO")
        else:
            print("YES", empty_time)


find_empty_time()
