# A. Equality

import string

n, k = map(int, input().split())
s = input()

letters = string.ascii_uppercase[:k]
st = set(s)

ans = 0

if len(st) == k:
    min_occurences = 100001
    for letter in st:
        cnt = s.count(letter)
        if cnt < min_occurences:
            min_occurences = cnt
    ans = min_occurences * 3

print(ans)
