import math


def main():
    n, m = map(int, input().split())
    if n % m == 0:
        print("YES")
    else:
        print("NO")


if __name__ == "__main__":
    t = int(input())
    for i in range(t):
        main()
