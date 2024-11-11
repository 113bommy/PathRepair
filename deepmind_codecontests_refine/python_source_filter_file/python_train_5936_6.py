#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
input:
3
abcbdab
bdcaba
abc
abc
abc
bc

output:
4
3
2

"""
import sys


def lcs(A, B):
    m, n = len(A), len(B)
    count_list = [[0] * (n + 1) for _ in range(m + 1)]

    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if A[i - 1] == B[j - 1]:
                count_list[i][j] = count_list[i - 1][j - 1] + 1
            elif count_list[i - 1][j] >= count_list[i][j - 1]:
                count_list[i][j] = count_list[i - 1][j]
            else:
                count_list[i][j] = count_list[i][j - 1]

    return count_list[m][n]


def lcs_better(A, B):
    costs = [0]
    for c in B:
        for index in range(len(costs) - 1, -1, -1):
            print(costs, index + 1)
            x_findex_index = A.find(c, costs[index])
            if x_findex_index != -1:
                if index + 1 < len(costs):
                    costs[index + 1] = min(costs[index + 1], x_findex_index + 1)
                else:
                    costs.append(x_findex_index + 1)
    return len(costs) - 1


if __name__ == '__main__':
    _input = sys.stdin.readlines()
    pair_num = int(_input[0])

    word_list = _input[1:]
    # assert len(word_list) == 2 * pair_num
    for k in range(0, len(word_list), 2):
        print(lcs_better(word_list[k].strip(), word_list[k + 1].strip()))