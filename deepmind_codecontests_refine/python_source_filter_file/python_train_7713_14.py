from math import floor


def calculate(num):
    """
    Calculate sum of digits
    """
    result = 0
    count = 0
    if len(num) == 1:
        return 0
    while True:
        result = sum(int(x) for x in list(num))
        count += 1
        if result > 10:
            num = str(result)
            result = 0
        else:
            break
    return count


if __name__ == "__main__":
    num = input()
    result = calculate(num)
    print(result)
