def solve(ab_dist, lights_dist, speed, green, red):
    time = lights_dist // speed
    q = time % (green + red)
    if q < green:
        time = ab_dist / speed
    else:
        time = red+green-q
        if lights_dist % speed > 0:
            time -= (red+green - q) / speed
        time += ab_dist / speed
    return time


if __name__ == '__main__':
    a, b, c, d, e, = [int(x) for x in input().split()]
    print(solve(a, b, c, d, e))
