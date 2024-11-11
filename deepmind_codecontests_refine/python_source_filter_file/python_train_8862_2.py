from collections import Counter
from operator import itemgetter


def prepare_data():
    _ = input()
    team = [int(i) for i in input().split()]
    return sorted([(el, count) for el, count in Counter(team).items()], key=itemgetter(0))


def find_max_team_count(countered_and_sorted_team):
    left_pointer = countered_and_sorted_team[0][0]
    left_pointer_idx = 0
    left_pointer_count = countered_and_sorted_team[0][1]
    current_sum = countered_and_sorted_team[0][1]
    max_sum = countered_and_sorted_team[0][1]
    for i in countered_and_sorted_team[1:]:
        if i[0] - left_pointer > 5:
            left_pointer_idx += 1
            current_sum -= left_pointer_count
            left_pointer = countered_and_sorted_team[left_pointer_idx][0]
            left_pointer_count = countered_and_sorted_team[left_pointer_idx][1]
        current_sum += i[1]
        if current_sum > max_sum:
            max_sum = current_sum
    return max_sum


if __name__ == '__main__':
    countered_and_sorted_team = prepare_data()
    max_sum = find_max_team_count(countered_and_sorted_team)
    print(max_sum)
