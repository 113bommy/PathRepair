# https://codeforces.com/problemset/problem/1185/A
from sys import stdin

if __name__ == "__main__":
    pos_a, pos_b, pos_c, dist = [int(n) for n in stdin.readline().strip().split(" ")]
    left, center, right = sorted([pos_a, pos_b, pos_c])
    movements_left = dist - (center - left) if left - center < dist else 0
    movements_right = dist - (right - center) if right - center < dist else 0
    print(movements_left + movements_right)