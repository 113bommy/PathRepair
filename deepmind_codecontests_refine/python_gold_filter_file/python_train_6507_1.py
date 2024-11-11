'''
Jana Goodman

5A chat server

This  is

Codeforces
Beta
Round
5

for odds, alternate starting left
  closer to left / right / ...
'''
import sys

LEFT = 0
RIGHT = 1
SPACE = ' '
STAR = '*'

if __name__ == '__main__':
    lines = [line.strip() for line in sys.stdin]
    left_or_right = LEFT
    width = max(len(line) for line in lines)
    print(STAR * (width + 2))
    for line in lines:
        fill_len = width - len(line)
        if fill_len % 2 == 0:
            spaces = SPACE * (fill_len // 2)
            print(f'{STAR}{spaces}{line}{spaces}{STAR}')
        else:
            sp_len = fill_len // 2
            if left_or_right == LEFT:
                spaces1, spaces2 = SPACE * sp_len, SPACE * (sp_len + 1)
                left_or_right = RIGHT
            else:
                spaces1, spaces2 = SPACE * (sp_len + 1), SPACE * sp_len
                left_or_right = LEFT
            print(f'{STAR}{spaces1}{line}{spaces2}{STAR}')
    print(STAR * (width + 2))
