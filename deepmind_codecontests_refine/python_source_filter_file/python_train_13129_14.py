
# Main
def run():
    t = int(input())

    while t > 0:
        n, x, y, d = map(int, input().split())

        if (y - x) % d == 0:
            print((y - x) // d)
        else:
            le, ri = False, False
            if (y - 1) % d == 0:
                rem = (x - 1) % d
                left = abs(x - 1) // d
                if rem > 0:
                    left += 1
                left += (abs(y - 1) // d)
                le = True

            if (n - y) % d == 0:
                rem2 = (n - x) % d
                right = abs(n - x) // d
                if rem2 > 0:
                    right += 1
                right += (abs(n - y) // d)
                ri = True

            if not le and not ri:
                print(-1)
            elif not le:
                print(abs(right))
            elif not ri:
                print(abs(left))
            else:
                print(abs(min(left, right)))

        t -= 1

# end main


# Program Start
if __name__ == "__main__":
    run()