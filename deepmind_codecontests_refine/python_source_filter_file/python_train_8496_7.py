def main():
    n = int(input())
    day = 0
    for _ in range(n):
        s, d = map(int, input().split())
        # s + k d > day
        # k d > day - s
        # k > (day - s) / d
        k = max(0, (day - s) / d)
        while s + k * d <= day:
            k += 1

        day = s + k * d

    print(day)

main()
