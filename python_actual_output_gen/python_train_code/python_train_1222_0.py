length_first = int(input())
first = list(map(int, input().split()))
length_second = int(input())
second = list(map(int, input().split()))
if sum(first) != sum(second):
    print(-1)
else:
    solution = 0
    pos_first = 1
    pos_second = 1
    sum = first[0] - first[0]
    while pos_first < length_first and pos_second < length_second:
        if sum == 0:
            solution += 1
            sum = first[pos_first] - second[pos_second]
            pos_first += 1
            pos_second += 1
        elif sum > 0:
            sum -= second[pos_second]
            pos_second += 1
        else:
            sum += first[pos_first]
            pos_first += 1

    solution += 1  # at the end, always one extra number, the addition of the remaining
    print(solution)