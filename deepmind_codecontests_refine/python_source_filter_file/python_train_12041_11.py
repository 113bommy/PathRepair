import sys
mod = 1000000007
def get_array(): return list(map(int, sys.stdin.readline().split()))
def get_ints(): return map(int, sys.stdin.readline().split())
def input(): return sys.stdin.readline()
def print_array(a): print(" ".join(map(str, a)))
def main():
    n = int(input())
    if n < 6: print("-1")
    else:
        print("1 2\n1 3\n1 4")
        for val in range(4, n + 1):
            print("2 " + str(val))
    for val in range(2, n + 1): print("1 " + str(val))
if __name__ == "__main__":
    main()