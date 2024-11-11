#!/usr/bin/env python3

from string import ascii_lowercase

a, b, c = input(), input(), input()

count_char_a = [a.count(x) for x in ascii_lowercase]
count_char_b = [b.count(x) for x in ascii_lowercase]
count_char_c = [c.count(x) for x in ascii_lowercase]

possible_b = 10 ** 5
for i in range(26):
    if count_char_b[i] > 0:
        possible_b = min(possible_b, count_char_a[i] // count_char_b[i])

num_b = possible_b
num_c = 0
possible_c = 10 ** 5
for i in range(possible_b + 1):
    for j in range(26):
        count_char_a[i] -= count_char_b[j] * int(i > 0)
        if count_char_c[j] > 0:
            possible_c = min(possible_c, count_char_a[j] // count_char_c[j])
    if i * possible_c > num_c + num_b:
        num_c = possible_c
        num_b = i

remain_count_a = [a.count(x) for x in ascii_lowercase]
for i in range(26):
    remain_count_a[i] -= count_char_b[i] * num_b
    remain_count_a[i] -= count_char_c[i] * num_c

result = ""
result += b * num_b
result += c * num_c
for i, c in enumerate(ascii_lowercase):
    result += c * remain_count_a[i]

print(result)
