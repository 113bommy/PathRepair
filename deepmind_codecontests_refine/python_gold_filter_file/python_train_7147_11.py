import random
import math
from collections import defaultdict
import itertools
from sys import stdin, stdout
import operator


def main():
    z = ''
    #p = lambda *a: print(*a, flush = True)
    d = defaultdict()
    #for _ in range(int(stdin.readline())):
    n, k = list(map(int, input().split()))
    a = list(map(int, input().split()))
    t = list(map(int, input().split()))

    initial_sum = sum(a[:k])

    all_sum = [0]
    for i in range(n):
        if t[i] == 1:
            all_sum.append(all_sum[-1]+a[i])
        else:
            all_sum.append(all_sum[-1])

    m= all_sum[-1]

    for i in range(n-k+1):
        t_sum = all_sum[i] + initial_sum + all_sum[-1]-all_sum[i+k]
        m = max(m, t_sum)
        if i+k<n:
            initial_sum = initial_sum - a[i]+a[i+k]
    print(m)



    #     z += str(ans) + '\n'
    # stdout.write(z)

#for interactive problems
#print("? {} {}".format(l,m), flush=True)
#or print this after each print statement
#sys.stdout.flush()


if __name__ == "__main__":
    main()