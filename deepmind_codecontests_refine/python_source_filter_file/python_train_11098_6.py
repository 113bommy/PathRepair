#!/usr/bin/python3


def main():
    start, end = input().split()
    time = int(input())
    clock = "v<^>"

    if not (time%2):
        print("undefined")
    elif (clock[(clock.index(start) + time)%4] == end):
        print("CW")
    else:
        print("CCW")


if __name__ == "__main__": main()

