from sys import stdin


def main():
    n = int(stdin.readline())
    if  ((n*(n+1))/2)%2 == 0:
        print(0)
    else:
        print(1)
main()