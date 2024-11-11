def main():
    s = input() == "12"
    h, m = map(int, input().split(':'))
    if not 0 <= h - s < (2 - s) * 12:
        h = (h - s) % ((2 - s) * 10) + s
    print("{:0>2d}:{:0>2d}".format(h, m % 60))

    if __name__ == '__main__':
        main()
