def read_nums():
    return [int(x) for x in input().split()]


def count_deletes(nums, m, k):
    pass


def main():
    n, k, m = read_nums()
    nums = sorted(read_nums())
    cum_nums = [nums[0]]
    for i in range(1, len(nums)):
        cum_nums.append(nums[i] + cum_nums[i-1])

    total_sum = cum_nums[-1]

    results = []
    for del_index in range(min(m, n)):
        right_sum = (total_sum - cum_nums[del_index - 1]) if del_index > 0 else total_sum
        elem_left = n - del_index
        to_add = min(m - del_index, k * elem_left)
        cur_res = (right_sum + to_add) / elem_left
        results.append(cur_res)
    print(max(results))


if __name__ == '__main__':
    main()
