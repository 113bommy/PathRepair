#author : dokueki

import sys
INT_MAX = sys.maxsize
INT_MIN = -(sys.maxsize)-1
sys.setrecursionlimit(10**7)
mod = 1000000007


def main():
    n, m = map(int, sys.stdin.readline().split())
    a = list(map(int, sys.stdin.readline().split()))
    a.sort()
    if m == 0:
        print("YES")
    else:
        if a[-1] == n or a[0] == 1:
            print("NO")
        else:
            flag = True
            for i in range(m-2):
                if a[i + 2] - a[i] == 2:
                    flag = False
                    break
            print("YES" if flag else "NO")


if __name__ == "__main__":
    main()
