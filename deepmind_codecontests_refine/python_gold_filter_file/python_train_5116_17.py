"""
## Name of Prob
B. Alyona and a Narrow Fridge

## Link
https://codeforces.com/contest/1119/problem/B

## Note
can install 'arbitrary number' of shelves
She can not put a bottle on top of another bottle

## Input
n, h : num of bottles, height of fridge
a_i : height of i-th bottle (1 <= a_i <= h)

## Output
maximum num of bottles?

## Strategy
find possible k using binary search

select temporal k, and sort given a[:k]
stack from shortest to highest one,
choose two pair of bottle and install shelf on the top of second one.
if height of stack exceed given h, regard it as impossible case
"""
n, h = map(int, input().split())
a = list(map(int, input().split()))


def is_possible(h, a):
    cur_h = 0
    for i in range(0, len(a), 2):
        bottle_height = a[i]
        if cur_h + bottle_height > h:
            return False
        cur_h += bottle_height
    return True


l, r = 0, n
solution = 0
while l <= r:
    k = (l + r) // 2
    new_a = list(sorted(a[:k], reverse=True))

    if is_possible(h, new_a):
        l = k + 1
        solution = k
    else:
        r = k - 1
print(solution)
