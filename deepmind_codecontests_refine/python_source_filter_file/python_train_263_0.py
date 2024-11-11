#!/usr/bin/env python3


def main():
    try:
        while True:
            n = int(input())
            req = [tuple(map(int, input().split())) for i in range(n)]
            used = [(req[0][0], req[0][0] + req[0][1])]
            print(used[0][0], used[0][1] - 1)
            for start, dur in req[1:]:
                last = 1
                for a, b in used:
                    if last <= start and start + dur < a:
                        used.append((start, start + dur))
                        used.sort()
                        print(start, start + dur - 1)
                        break
                    last = b
                else:
                    if start >= used[-1][1]:
                        used.append((start, start + dur))
                        used.sort()
                        print(start, start + dur - 1)
                    else:
                        last = 1
                        for a, b in used:
                            if a - last >= dur:
                                used.append((last, last + dur))
                                used.sort()
                                break
                            last = b
                        else:
                            used.append((last, last + dur))
                            # used.sort()
                        print(last, last + dur - 1)

    except EOFError:
        pass


main()
