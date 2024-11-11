def main(n):
    if n <= 1:
        return "-1"
    l = list(reversed(list(range(1, n + 1))))
    return ' '.join(list(map(str, l)))

print(main(int(input())))
