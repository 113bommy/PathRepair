from collections import defaultdict, deque, Counter, OrderedDict
import threading,sys

def main():
    n = int(input())
    ans = 1
    for i in map(int,input().split()):
        ans |= i
    b = 1
    for j in map(int,input().split()):
        b |= j
    print(ans + b)


if __name__ == "__main__":
    """sys.setrecursionlimit(400000)
    threading.stack_size(40960000)
    thread = threading.Thread(target=main)
    thread.start()"""
    main()