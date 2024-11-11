import sys

def read_arr(dtype=int):
    return [dtype(c) for c in sys.stdin.readline().strip().split()]

if __name__ == "__main__":
    n, h = read_arr()
    heights = read_arr()
    print(sum((1 if a < h else 2 for a in heights)))
