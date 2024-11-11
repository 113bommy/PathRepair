import math


def main():
    k, d, t = [int(x) for x in input().split()]
    time = 0.0
    k = (k, 2 * t)[k > 2*t]

    val = d * (math.ceil(k / d))

    a = t // (k + (val - k) / 2)
    b = t % (k + (val - k) / 2)
    time += val * a
    b -= k
    time += k
    if b < 0:
        time += b
    if b > 0:
        b -= (val - k) / 2
        time += val - k
        if b < 0:
            time += b * 2

    print(time)


if __name__ == "__main__":
    main()
