if __name__ == "__main__":
    n = int(input())
    s = input()
    factors = [x for x in range(n, 1, -1) if n % x == 0]

    for factor in factors:
        part1 = s[:factor]
        part1 = part1[::-1]
        part2 = s[factor:]
        s = part1 + part2

    print(s)
