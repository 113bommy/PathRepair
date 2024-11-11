import sys
import itertools

def find_floors(peak, ms):
    score = 0
    current_height = ms[peak]
    for m in reversed(ms[:peak]):
        current_height = min(m, current_height)
        score += current_height
    current_height = ms[peak]
    for m in ms[peak:]:
        current_height = min(m, current_height)
        score += current_height

    return score

def print_soln(peak, ms):
    output = [-1 for i in range(len(ms))]

    current_height = ms[peak]
    for i, m in enumerate(reversed(ms[:peak])):
        current_height = min(m, current_height)
        output[peak + 1 - i] = current_height
    current_height = ms[peak]
    for i, m in enumerate(ms[peak:]):
        current_height = min(m, current_height)
        output[peak + i] = current_height

    for i in output:
        print(i)

def main():
    lines = []
    for l in sys.stdin:
        lines.append(l)

    ms = [int(i) for i in lines[1].split()]
    winner = 0
    winner_index = 0
    for i in range(len(ms)):
        v = find_floors(i, ms)
        if v > winner:
            winner_index = i
            winner = v

    print_soln(winner_index, ms)

main()
