def find_expected_people(people_count, probability, seconds):
    # the probability after i seconds to have k people on the escalator
    current_row = [0.] * (seconds + 1)
    current_row[0] = 1.

    for sec in range(1, seconds + 1):
        next_row = [x * (1. - probability) for x in current_row]
        next_row[-1] = current_row[-1]

        for person in range(people_count):
            next_row[person + 1] += current_row[person] * probability
        current_row = next_row

    return sum(index * value for index, value in enumerate(current_row))


def main():
    raw_input = input().split()
    people_count = int(raw_input[0])
    probability = float(raw_input[1])
    seconds = int(raw_input[2])

    print(find_expected_people(people_count, probability, seconds))

if __name__ == '__main__':
    main()
