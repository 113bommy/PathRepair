def main():
    t = int(input())

    for _ in range(t):
        n = int(input())
        prices = [int(elem) for elem in input().split()]

        counter = 0
        minimum = 10000001
        for price in reversed(prices):
            if price < minimum:
                minimum = price
            else:
                counter += 1

        print(counter)

main()
