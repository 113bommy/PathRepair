import sys

input = sys.stdin.readline


############ ---- Input Functions ---- ############
def inp():
    return (int(input()))


def inlt():
    return (list(map(int, input().split())))


def insr():
    s = input()
    return (list(s[:len(s) - 1]))


def invr():
    return (map(int, input().split()))


def main():
    v = insr()
    y = int(v[1])
    x = ord(v[0])-ord('a')
    moves = []
    for i in range(-1, 2):
        for j in range(-1,2):
            if i == 0 and j == 0:
                continue
            moves.append((i, j))
    c = 0
    for m in moves:
        if 0<= x+m[0]<=8 and  0<= y+m[1]<=8:
            c+=1
    print(c)
if __name__ == "__main__":
    # sys.setrecursionlimit(10 ** 6)
    # threading.stack_size(10 ** 8)
    # t = threading.Thread(target=main)
    # t.start()
    # t.join()
    main()
