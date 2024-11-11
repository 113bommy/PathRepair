def check(s1, s2):
    print("sum right: " + str(s1))
    print("sum left: " + str(s2))
    print()


def check_winner(input):
    data = list(map(int, input.split(" ")))
    output = 0
    r_sum = 0
    l_sum = 0
    start = 0
    end = data[len(data) - 1]

    while start <= end:
        if r_sum > l_sum:
            l_sum += data[end]
            end -= 1
        else:
            r_sum += data[start]
            start += 1

        if r_sum == l_sum:
            output = r_sum

    return output


if __name__ == "__main__":
    header = input()
    data = input()
    print(check_winner(data))
