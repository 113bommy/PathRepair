import math
import sys


def trapezoid(top_angle, area, a):
    bot_angle = (math.pi - top_angle) / 2
    bot_side = (-a * math.sin(bot_angle) + math.sqrt(
        ((a * math.sin(bot_angle)) ** 2) + 4 * math.cos(bot_angle) * math.sin(bot_angle) * area)) / (
               2 * math.cos(bot_angle) * math.sin(bot_angle))
    return bot_side * math.sin(bot_angle)


if __name__ == '__main__':
    n, h = [int(num) for num in input().split()]
    triangle_area = 0.5 * h * 1
    part_area = triangle_area / n
    top_angle = 2 * math.atan(0.5 / h)
    top_side = math.sqrt(2 * part_area / math.sin(top_angle))
    top_height = top_side * math.cos(top_angle / 2)
    top_low_side = 2 * math.sqrt(top_side ** 2 - top_height ** 2)
    parts = []
    parts.append(top_height)
    h = top_height
    # bot = top_low_side
    s = ""
    for i in range(0, n - 2):
        # h_trap = trapezoid(top_angle, part_area, bot)
        h_trap = h * math.sqrt(i + 2)
        parts.append(h_trap)
        h = h_trap
        # bot = bot + h_trap * 2 / math.tan(math.pi - top_angle)
    for i in range(0, len(parts)):
        print(parts[i])
