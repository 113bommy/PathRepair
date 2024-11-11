import math


def solve(n, k, m, c):
    counter_original = [0] * (k + 1)
    counter = [0] * (k + 1)
    for m_i in m:
        counter_original[m_i] += 1
        counter[m_i] += 1

    for i in reversed(range(1, k)):
        counter[i] += counter[i + 1]

    total_cases_needed = 0
    for i in reversed(range(1, k + 1)):
        cases_needed = int(math.ceil(counter[i] / c[i - 1]))
        total_cases_needed = max(total_cases_needed, cases_needed)

    current_cases = [[] for _ in range(total_cases_needed)]
    offset = 0
    for i in reversed(range(1, k + 1)):
        reminder = counter_original[i]
        for _ in range(reminder):
            current_cases[offset % total_cases_needed].append(i)
            offset += 1

    return current_cases


def main():
    n, k = map(int, input().split())
    m = list(map(int, input().split()))
    c = list(map(int, input().split()))
    cases = solve(n, k, m, c)
    print(len(cases))
    for case in cases:
        case_data = ' '.join(map(str, case))
        print(f'{len(case)} {case_data}')


if __name__ == '__main__':
    main()
