__author__ = 'alexkane'

from sys import stdin

if __name__ == "__main__":
    number_of_sticks = int(stdin.readline().rstrip('\n'))
    second_line = stdin.readline().rstrip('\n')
    sticks = [int(x) for x in second_line.split(' ')]

def execute(number_of_sticks, sticks):
    max = 0
    if number_of_sticks < 4:
        return max
    else:
        sticks.sort()
        sticks.reverse()
        current_max = 0
        i = 1
        while i < len(sticks):
            if sticks[i] - sticks[i - 1] <= 1:
                if current_max == 0:
                    current_max = sticks[i]
                    i += 1
                else:
                    max += current_max * sticks[i]
                    current_max = 0
                    i += 1
            i += 1
        return max


if __name__ == "__main__":
    print(execute(number_of_sticks, sticks))