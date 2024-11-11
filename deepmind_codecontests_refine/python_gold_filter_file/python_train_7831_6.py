from sys import stdin

input = stdin.readline


def main():
    test = int(input())

    for t in range(test):
        s = input().strip()
        zero = s.count('0')
        one = s.count('1')

        if zero == 0 or one == 0:
            print(s)
        else:
            print('01'*len(s))


main()
