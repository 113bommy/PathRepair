
def count(sequence):
    result = 0
    current_length = 1
    for (i, x) in enumerate(sequence):
        if i == 0: continue
        if sequence[i - 1] == x:
            current_length += 1
            continue

        if current_length % 2 == 0:
            result += 1

        current_length = 1

    if current_length == 2:
        result += 1

    return result


def main():
    sequence = input()
    print(count(sequence))


if __name__ == '__main__':
    main()
