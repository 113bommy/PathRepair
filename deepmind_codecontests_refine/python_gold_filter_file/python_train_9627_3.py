from collections import Counter


def main():
    letter = Counter(input())
    journal = Counter(input())

    a = b = 0
    for k in letter:
        d = min(letter[k], journal[k])
        letter[k] -= d
        journal[k] -= d
        a += d

    for k in letter:
        c = k.swapcase()
        d = min(letter[k], journal[c])
        letter[k] -= d
        journal[c] -= d
        b += d

    print(a, b)


if __name__ == "__main__":
    main()