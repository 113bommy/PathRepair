def main():
    n = int(input())
    c = 0
    minutes = [int(i) for i in input().split()]
    for m in minutes:
        if m - c - 1 >= 15:
            print(c + 15)
            return
        c = m
    if m + 14 <= 90:
        print(m + 14)
    else:
        print(90)

main()
