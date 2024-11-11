# import time
def index(key, item, index):
    if key in index:
        index[key].add(item)
    else:
        index[key] = set([item])

def schedule(times):
    index_by_a = {}
    index_by_b = {}
    result_indexs = []
    for i in range(len(times)):
        a, b = times[i]
        index(a, i, index_by_a)
        index(b, i, index_by_b)
    b_keys = sorted(list(index_by_b.keys()))
    # a_keys = sorted(list(index_by_a.keys()))
    a_min = 0
    while 1:
        # collect pool
        pool = set()
        for k, v in index_by_a.items():
            if k >= a_min:
                pool |= v
        if not pool:
            break
        # greedy select.
        for k in (ele for ele in b_keys if ele > a_min):
            candidates = pool & index_by_b[k]
            if candidates:
                chosen = candidates.pop()
                result_indexs.append(chosen)
                a, b = times[chosen]
                a_min = b
                break
    return [times[i] for i in result_indexs]
                
def test_schedule():
    i = ((0, 4), (2, 4), (0, 2), (0, 1), (1, 2), (2, 3), (3, 4))
    result = schedule(i)
    print('len:', len(result))
    for ele in result:
        print(ele)

def solve(n, a_l):
    index_by_sum = {}
    for i in range(n):
        sum_ = 0
        for j in range(i + 1, n + 1):
            sum_ += a_l[j - 1]
            if sum_ in index_by_sum:
                index_by_sum[sum_].append((i, j))
            else:
                index_by_sum[sum_] = [(i, j)]
    result = []
    for sum_, times in index_by_sum.items():
        sub_result = schedule(times)
        if len(sub_result) > len(result):
            result = sub_result
    return result

def main():
    n = int(input())
    a_l = list(map(int, input().split()))
    # tick = time.time()
    result = solve(n, a_l)
    print(len(result))
    for a, b in result:
        print(a + 1, b)
    # tock = time.time()
    # print('T:', round(tock - tick, 5))

if __name__ == "__main__":
    main()