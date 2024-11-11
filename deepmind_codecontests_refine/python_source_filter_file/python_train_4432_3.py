from sys import stdin


def shift_time(seat):
    if seat == 'f':
        return 1
    if seat == 'e':
        return 2
    if seat == 'd':
        return 3
    if seat == 'a':
        return 4
    if seat == 'b':
        return 5
    if seat == 'c':
        return 6


def solve(row, shift):
    long_moves = row//4
    result = long_moves * (12 + 1 + 3)
    if row % 4 % 2 == 1:
        result += 7
    return result + shift


if __name__ == "__main__":
    if not True:
        in_str = next(stdin).strip("\r\n")

        print(str(solve(int(in_str[:-1])-1, shift_time(in_str[-1]))))
    else:
        bumpers = [
            "1f",
            "2d",
            "4a",
            "5e"
        ]
        for test_word in bumpers:
            print(str(solve(int(test_word[:-1])-1, shift_time(test_word[-1]))))