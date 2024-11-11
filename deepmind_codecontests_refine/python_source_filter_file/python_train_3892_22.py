import sys
from collections import defaultdict

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
    d = defaultdict(lambda : 0)
    s = input().strip()
    for c in s:
        d[c]+=1
    c = 0
    for k, v in d.items():
        if v % 2 != 0:
            c += 1
    print("First" if (c<=1 or c%2==0) else "Second")




if __name__ == "__main__":
    # sys.setrecursionlimit(10 ** 6)
    # threading.stack_size(10 ** 8)
    # t = threading.Thread(target=main)
    # t.start()
    # t.join()
    main()
