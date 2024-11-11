#!usr/bin/env python3

import sys


def main():
    WINNING_HANDS = [
                '111', '222', '333', '444', '555', '666', '777', '888', '999',
                '123', '234', '345', '456', '567', '678', '789'
            ]

    num_of_datasets = int(sys.stdin.readline().strip('\n'))
    datasets = [{'R': [], 'G': [], 'B': []} for _ in range(num_of_datasets)]
    results = list()

    for dataset in range(num_of_datasets):
        n_set = [num for num in sys.stdin.readline().strip('\n').split()]
        c_set = [colour for colour in sys.stdin.readline().strip('\n').split()]
        for idx, colour in enumerate(c_set):
            if colour == 'R':
                datasets[dataset]['R'].append(n_set[idx])
            elif colour == 'G':
                datasets[dataset]['G'].append(n_set[idx])
            elif colour == 'B':
                datasets[dataset]['B'].append(n_set[idx])

        match_count = int()

        for rgb_key in datasets[dataset]:
            nums = sorted(datasets[dataset][rgb_key])

            for hand in WINNING_HANDS:
                while hand[0] in nums and hand[1] in nums and hand[2] in nums:
                    tmp = nums.copy()
                    if hand[0] in tmp:
                        tmp.pop(tmp.index(hand[0]))
                        if hand[1] in tmp:
                            tmp.pop(tmp.index(hand[1]))
                            if hand[2] in tmp:
                                tmp.pop(tmp.index(hand[2]))
                                match_count += 1
                                nums = tmp
                            else:
                                break
                        else:
                            break
                    else:
                        break

                    if match_count == 3:
                        results.append(1)
                        continue

        if dataset < num_of_datasets-1 and match_count != 3:
            results.append(0)

    for result in results:
        print(result)


if __name__ == '__main__':
    main()