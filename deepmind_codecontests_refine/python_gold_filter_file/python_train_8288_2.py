#!/usr/bin/env python


def main():
    flags = input()
    first = input()
    second = input()
    skip = len(first)

    possible = 0
    at = flags.find(first)
    if at >= 0:
        at += skip
        if flags.find(second, at) >= at:
            possible += 1

    flags = flags[::-1]
    at = flags.find(first)
    if at >= 0:
        at += skip
        if flags.find(second, at) >= at:
            possible += 2

    if possible == 1:
        print("forward")
    elif possible == 2:
        print("backward")
    elif possible == 3:
        print("both")
    else:
        print("fantasy")


if __name__ == '__main__':
    main()
