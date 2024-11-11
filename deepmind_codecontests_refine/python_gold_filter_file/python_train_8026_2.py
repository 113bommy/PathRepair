import sys

if __name__ == '__main__':
    throwaway = int(input())  # don't need count
    max_side_size = 0
    for point_line in sys.stdin:
        x, y = point_line.split()
        x = int(x)
        y = int(y)
        if x + y > max_side_size:
            max_side_size = x+y
    print(max_side_size)