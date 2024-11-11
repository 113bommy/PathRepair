from sys import stdin, stdout
import math


def f1(keys, counter, k):
    first_el = keys[0]
    first_count = counter[first_el] - (k - 1)
    answer = first_el * first_count
    for i in range(1, len(keys)):
        el = keys[i]
        count = counter[el]
        part = el * count
        answer = answer + part
    return answer


def f2(keys, counter, k):
    first_el = keys[0]
    first_count = counter[first_el]
    if first_count % k == 0:
        big = first_el * (first_count // k)
        small = big
        equal = True
    else:
        big = first_el * math.ceil(first_count / k)
        small = first_el * math.floor(first_count / k)
        equal = False
    for i in range(1, len(keys)):
        el = keys[i]
        if not equal:
            return small + el
        count = counter[el]
        if count % k == 0:
            part_common = el * (count // k)
            big += part_common
            small = big
        else:
            part_big = el * math.ceil(count / k)
            big += part_big
            part_small = el * math.floor(count / k)
            small += part_small
            equal = False
    return big


def main():
    t = int(input())
    # t = 1
    for _ in range(t):
        n, k = [int(i) for i in input().split()]
        s = input()
        counter = {}
        for el in s:
            if el not in counter:
                counter[el] = 0
            counter[el] += 1
        keys = sorted(counter.keys())
        count = 0
        count_type = 0
        for el in keys:
            count += counter[el]
            count_type += 1
            if count >= k:
                break
        if count_type > 1:
            print(keys[count_type - 1])
            continue
        v1 = f1(keys, counter, k)
        v2 = f2(keys, counter, k)
        if v1 < v2:
            print(v1)
        else:
            print(v2)


main()
