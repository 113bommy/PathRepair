#!/usr/bin/env python3

n_list = []
m_list = []
a_list = []

while True:
    n, m = list(map(int, input().split(' ')))

    if n == 0 and m == 0:
        break

    a = list(map(int, input().split(' ')))

    n_list.append(n)
    m_list.append(m)
    a_list.append(a)


for n, m, a in zip(n_list, m_list, a_list):
    m_sum = 0
    for i in range(0, n):
        for j in range(i + 1, n):
            tmp = a[i] + a[j]
            if m_sum < tmp and tmp <= m:
                m_sum = tmp

    if m_sum > 0:
        print(m_sum)
    else:
        print('None')

