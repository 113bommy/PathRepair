def main():
    for _ in range(int(input())):
        h, m = map(int, input().split())
        print(((24 - h - 1) * 60 * 60) + (60 - m))
main()
