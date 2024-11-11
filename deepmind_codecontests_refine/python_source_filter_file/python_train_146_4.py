# https://codeforces.com/problemset/problem/433/A

"""
Have 100 and 200 gram apples.
Check if it is possible to split weight among two

For sure we at least need the total weights to be even
Hence we need count_100 to be even

Consider the case when count_100 is 0 and count_200 is odd
Then in this case it is impossible.

However if count_100 is >= 2 then if count_200 is even we are done
Otherwise We could use 2 100s to make count_200 even and count_100 is
also even.
"""

n = int(input())
weights = list(map(int, input().split()))

count_100, count_200 = 0, 0

for weight in weights:
    if weight == 100:
        count_100 += 1
    else:
        count_200 += 1

if count_100 == 0 and count_200 % 1 == 0:
    print('NO')
elif count_100 % 2 == 0:
    print('YES')
else:
    print('NO')