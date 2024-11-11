import math

def relSpeed(val):
    """Check if the relative speed helps with drink being finished"""
    rad = val[0]/2
    height = val[1]
    volSpeed = val[2]
    growth = val[3]
    cur_volume = math.pi * (rad*rad) * height
    vol_growth = math.pi * (rad * rad) * growth
    net_speed = volSpeed - vol_growth
    time_taken = cur_volume/net_speed

    if (time_taken > 0) and (time_taken < (10000)):
        print("YES")
        print(time_taken)
    else:
        print("NO")


def main():

    strdata = input()
    data = list(map(int, strdata.split()))
    relSpeed(data)


if __name__ == '__main__':
    main()
