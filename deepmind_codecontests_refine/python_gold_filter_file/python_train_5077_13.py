# http://codeforces.com/contest/998/problem/0


def read_nums():
    return [int(x) for x in input().split()]


def find_cuts(nums):
    res = []
    n_even, n_odd = 0, 0
    for index, num in enumerate(nums):
        if num % 2 == 0:
            n_even += 1
        else:
            n_odd += 1
        if n_odd == n_even and index != len(nums) - 1:
            res.append(index)
    return res


def find_costs(nums, cuts):
    res = []
    for index in cuts:
        res.append(abs(nums[index] - nums[index + 1]))
    return res


def print_res(b, sorted_costs):
    res = 0
    spent = 0
    for cost in sorted_costs:
        if spent + cost <= b:
            res += 1
            spent += cost
    print(res)


def main():
    n, b = read_nums()
    nums = read_nums()
    cuts = find_cuts(nums)
    cut_costs = find_costs(nums, cuts)
    sorted_costs = sorted(cut_costs)
    print_res(b, sorted_costs)


if __name__ == '__main__':
    main()
