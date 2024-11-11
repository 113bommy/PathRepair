import sys
import math
import timeit
from collections import Counter
from random import randint

def main():
    n = int(input())
    a = [int(x) - 1 for x in input().split()]
    hash_value = [randint(1, 10**10) for i in range(n + 1)]
    hashes = [0 for i in range(n + 1)]
    hash_freq = Counter([0])
    freq = [0 for i in range(n)]
    pos = [[] for i in range(n)]

    res = 0
    start = 0
    for i in range(n):
        x = a[i]
        if len(pos[x]) >= 3:
            remove = pos[x][0] 
            pos[x].pop(0)

            while start <= remove:
                hash_freq[hashes[start]] -= 1
                start += 1

        before = freq[x]
        freq[x] = (freq[x] + 1) % 3
        hashes[i + 1] = hashes[i] + (freq[x] - before) * hash_value[x]
        res += hash_freq[hashes[i + 1]]
        hash_freq[hashes[i + 1]] += 1
        pos[x].append(i)
    print(res)


if __name__ == '__main__':
    start = timeit.default_timer()

    numTest = 1
    while numTest:
        main()
        numTest -= 1

    stop = timeit.default_timer()
    print('Time: ', stop - start, file = sys.stderr)  

