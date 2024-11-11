from sys import stdin


def nb_good_numbers(n):
    by_digit = {
        "0": 2,
        "1": 7,
        "2": 4,
        "3": 3,
        "4": 3,
        "5": 4,
        "6": 2,
        "7": 5,
        "8": 1,
        "9": 2,
    }
    result = 1
    for digit in n:
        result *= by_digit[digit]
    return result


if __name__ == "__main__":
    n = stdin.readline().rstrip()
    print(nb_good_numbers(n))
