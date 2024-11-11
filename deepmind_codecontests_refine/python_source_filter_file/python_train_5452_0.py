#!/usr/bin/env python3

from sys import stdin
from math import atan2, pi, degrees

def main():
    num_points = int(stdin.readline())
    angles = []

    for point in range(num_points):
        x, y = map(int, stdin.readline().split())
        angles.append(atan2_deg(y, x))

    # calculate best angle
    angles = sorted(angles)
    best = 360 - abs(angles[-1] - angles[0])
    for i in range(1, num_points):
        best = min(best, 360.0 - abs(angles[i] - angles[i - 1]))
    print(best)

def atan2_deg(y, x):
    return degrees(atan2(y, x) + pi)

if __name__ == '__main__':
    main()
