#!/usr/bin/env python3

def main():
    input()
    print(1 if any(map(lambda x: x == 1, map(int, input().split()))) else -1)


if __name__ == '__main__':
    main()
